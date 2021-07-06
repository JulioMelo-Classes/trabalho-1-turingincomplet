#include "func.h"
#include <iostream>

using namespace std;


vector<cash_type> tableval(size_t num) {
	switch (num) {
	case 1: return { 0,3 };
	case 2: return { 0,1,9 };
	case 3: return { 0,1,2,16 };
	case 4: return { 0,0.5, 2, 6, 12 };
	case 5: return { 0,0.5, 1, 3, 15,50 };
	case 6: return { 0,0.5, 1,2, 3, 30,75 };
	case 7: return { 0,0.5,0.5, 1,6, 12, 36,100 };
	case 8: return { 0,0.5,0.5, 1,3,6, 19, 90,720 };
	case 9: return { 0,0.5,0.5, 1,2,4, 8, 20,80,1200 };
	case 10: return { 0,0,0.5, 1,2,3, 5, 10,30,600,1800 };
	case 11: return { 0,0,0.5, 1,1,2,6, 15, 25,180,1000,3000 };
	case 12: return { 0,0,0,0.5, 1,2,4, 24, 72,250,500,2000,4000 };
	case 13: return { 0,0,0,0.5,0.5, 3,4, 5, 20,80,240,500,3000,6000 };
	case 14: return { 0,0,0,0.5,0.5, 2,3,5, 12, 50,150,500,1000,2000,7500 };
	case 15: return { 0,0,0,0.5,0.5, 1,2,5, 12, 50,150,300,600,1200,2500,10000 };
	}
	return { -1 };
}

set_of_numbers_type randhits(void) {
	set_of_numbers_type rand(80,0);
	iota(rand.begin(), rand.end(), 1);
	random_shuffle(rand.begin(),rand.end());
	rand.resize(20);
	return rand;
}
void printvec(set_of_numbers_type v) {
	cout << "[ ";
	for (auto it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << "]";
}

void printtable(std::vector<cash_type> t) {
	cout << "      ----------+-----------" << endl;
	cout<< "      Hits      | Retorno" << endl;
	for (size_t i=0; i<t.size(); i++) {
		if (i < 10) {
			cout << "      " << i << "         | " << t[i] << endl;
		}
		else cout << "      " << i << "        | " << t[i] << endl;
	}
	cout << "      ------------------------------------------------------------" << endl;
}

void generror(void) {
	cout << "arquivo invalido" << endl;
	exit(1);
}

void inserts(set_of_numbers_type& v) {
	int i, j;
	number_type	key;
	int n = v.size();
	for (i = 1; i < n; i++) {
		key = v[i];
		j = i - 1;
		while (j >= 0 && v[j] > key) {
			v[j + 1] = v[j];
			j = j - 1;
		}
		v[j + 1] = key;
	}
}
