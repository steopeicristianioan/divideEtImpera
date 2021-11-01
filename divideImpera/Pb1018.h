#include <iostream>
#include <fstream>

using namespace std;

/*
	Se consideră un șir cu n elemente, numere naturale. 
	Folosind metoda Divide et Impera, determinați câte elemente impare sunt în acest șir.
*/

class Pb1018
{
public:
	int n, v[1001];

	int ctImpare(int st, int dr) {
		if (st == dr) {
			if (v[st] % 2 == 1)
				return 1;
			return 0;
		}
		else {
			int mid = (st + dr) / 2;
			return ctImpare(st, mid) + ctImpare(mid + 1, dr);
		}
	}
	void solve() {
		ifstream fin("Fin.txt");
		fin >> n;
		for (int i = 0; i < n; i++)
			fin >> v[i];
		cout << ctImpare(0, n - 1);
	}
};

