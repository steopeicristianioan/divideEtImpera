#include <fstream>
#include <iostream>

using namespace std;

class Pb4
{
public:
	int n;

	int pow(int baza, int exp) { //ridicare la putere in timp logaritmic
		if (exp == 0)
			return 1;
		if (exp % 2 == 1)
			return baza * pow(baza, exp - 1);
		int p = pow(baza, exp / 2);
		return p * p;
	}
	void solve() {
		ifstream fin("Fin.txt");
		fin >> n;
		cout << pow(1, n);
	}
};

