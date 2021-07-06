#include<iostream>
#include<fstream>
#include <sstream>
#include <locale.h>
#include "KenoBet.h"
#include "func.h"
using namespace std;



int main(int argc, char* argv[]){
	setlocale(LC_ALL, "");
	int x;
	ifstream file;
	cout << ">>> Lendo arquivo de apostas ["<<argv[1]<<"], por favor aguarde.."<<endl;
	cout<<"--------------------------------------------------------------------" << endl;
	file.open(argv[1]);
	if (!file) {
		cout << "arquivo inexistente" << endl;
		exit(1);
	}
	srand((unsigned int)time(0));
	bool vef;
	string feed;
	cash_type wage;
	int rodas;
	KenoBet bet;
	file >> wage >>rodas;
	if (file.fail())
		generror();
	cash_type money=wage;
	bet.set_wage(wage);
	cash_type rodval = wage / rodas;
	getline(file,feed);
	int limit=0;
	while (file  >> x) {
		if (file.fail())
			generror();
		if (x > 80 ||x<1) {
			cout<<"numero invalido" << endl;
			exit(1);
		}
		limit++;
		if (limit > 15) {
			cout<<"muitos numeros" << endl;
			exit(1);
		}
		vef=bet.add_number(x);
		if (!vef) {
			cout<<"numero já colocado" << endl;
			exit(1);
		}
	}
	auto clonspots = bet.get_spots();
	inserts(clonspots);
	cout << ">>> Aposta lida com sucesso!" << endl;
	cout << "    Você apostará um total de $" << wage << " créditos." << endl;
	cout << "    Jogará um total de "<<rodas<<" rodadas, apostando $" << rodval << " créditos por rodada" <<'\n'<< endl;
	cout << "    Sua aposta tem 3 números, eles são :"; printvec(clonspots);
	cout << endl;
	auto ctable = tableval(bet.size());
	printtable(ctable);
	for (int i = 0; i < rodas; i++) {
		cout << "      Esta é a rodada #" << i + 1 << " de " << rodas << " sua aposta é $" << rodval << ". Boa sorte!" << endl;
		auto hits = randhits();
		inserts(hits);
		cout << "      Os números sorteados são :"; printvec(hits);
		cout << endl;
		auto chits =bet.get_hits(hits);
		auto multi = ctable[chits.size()];
		inserts(chits);
		cout<<"      Você acertou os números "; printvec(chits);
		cout << ", um total de " << chits.size() << " hits de " << bet.size()<<endl;
		cout << "      Sua taxa de retorno é " << multi << ", assim você sai com : $" << multi * rodval<<endl;
		money -= rodval;
		money += multi * rodval;
		cout << "      Você possui um total de : $" << money << " créditos." <<endl;
		cout<<"      ------------------------------------------------------------" << endl;
	}
	cout << ">>> Fim das rodadas!" << endl;
	cout << "--------------------------------------------------------------------" << '\n' << endl;
	cout << "======= Sumário =======" << endl;
	cout << ">>> Você gastou um total de $" << wage << " créditos" << endl;
	if (money > wage) {
		cout << ">>> Hooray! você ganhou $" << money - wage << " créditos!"<<endl;
	}
	else if (money < wage) {
		cout << ">>> Que pena! você perdeu $" << wage-money << " créditos"<<endl;
	}
	else cout << ">>> Bem, você não ganhou mais também nem perdeu" << endl;
	cout << ">>> Você está saindo do jogo com um total de $" << money << " créditos."<<endl;
return 0;
}