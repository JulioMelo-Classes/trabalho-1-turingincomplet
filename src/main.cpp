#include<iostream>
#include<fstream>
#include <sstream>
#include <locale.h>
#include "KenoBet.h"
#include "func.h"
using namespace std;


/*
Avaliação
Processamento do Arquivo de Entrada: 0,75 (faltou o processamento de caracteres e de formatação do arquivo de apostas)
Execução correta: 1
Interfcace Textual: 1
Documentação: 1
Compilação automatizada: 1
Organização em src, include, build, data: 0,8 (não organizou os arquivos no diretório data, ficando tudo no build)

Comentários
- Acho que seu editor de código deve estar configurado diferente do "padrão" pra código. Especialmente se for no windows,
vi que a codificação dos arquivos que vc enviou pro github são iso 8859, enquanto o padrão é utf8. Isso explica o motivo
do linux exibir estranhamente os caracteres. Inclusive, pode ser que dê algum problema após eu enviar as corresções,
uma vez que esses comentários estão com utf8. Verifique isso para próximas versões, o powershell suporta utf8, então
vc não deve ter problemas em executar no powershell o programa.
- Você poderia ter dividido melhor a parte de processamento de arquivos e da interface textual. Especialmente fazendo
duas classes uma com cada uma das responsabilidades.
*/

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
			cout<<"numero j� colocado" << endl;
			exit(1);
		}
	}
	auto clonspots = bet.get_spots();
	inserts(clonspots);
	cout << ">>> Aposta lida com sucesso!" << endl;
	cout << "    Voc� apostar� um total de $" << wage << " cr�ditos." << endl;
	cout << "    Jogar� um total de "<<rodas<<" rodadas, apostando $" << rodval << " cr�ditos por rodada" <<'\n'<< endl;
	cout << "    Sua aposta tem 3 n�meros, eles s�o :"; printvec(clonspots);
	cout << endl;
	auto ctable = tableval(bet.size());
	printtable(ctable);
	for (int i = 0; i < rodas; i++) {
		cout << "      Esta � a rodada #" << i + 1 << " de " << rodas << " sua aposta � $" << rodval << ". Boa sorte!" << endl;
		auto hits = randhits();
		inserts(hits);
		cout << "      Os n�meros sorteados s�o :"; printvec(hits);
		cout << endl;
		auto chits =bet.get_hits(hits);
		auto multi = ctable[chits.size()];
		inserts(chits);
		cout<<"      Voc� acertou os n�meros "; printvec(chits);
		cout << ", um total de " << chits.size() << " hits de " << bet.size()<<endl;
		cout << "      Sua taxa de retorno � " << multi << ", assim voc� sai com : $" << multi * rodval<<endl;
		money -= rodval;
		money += multi * rodval;
		cout << "      Voc� possui um total de : $" << money << " cr�ditos." <<endl;
		cout<<"      ------------------------------------------------------------" << endl;
	}
	cout << ">>> Fim das rodadas!" << endl;
	cout << "--------------------------------------------------------------------" << '\n' << endl;
	cout << "======= Sum�rio =======" << endl;
	cout << ">>> Voc� gastou um total de $" << wage << " cr�ditos" << endl;
	if (money > wage) {
		cout << ">>> Hooray! voc� ganhou $" << money - wage << " cr�ditos!"<<endl;
	}
	else if (money < wage) {
		cout << ">>> Que pena! voc� perdeu $" << wage-money << " cr�ditos"<<endl;
	}
	else cout << ">>> Bem, voc� n�o ganhou mais tamb�m nem perdeu" << endl;
	cout << ">>> Voc� est� saindo do jogo com um total de $" << money << " cr�ditos."<<endl;
return 0;
}