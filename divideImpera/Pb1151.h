#include <iostream>
#include <fstream>

using namespace std;

/*
	Se dă un vector cu n elemente numere naturale. 
	Folosind metoda Divide et Impera să se verifice
	dacă toate elementele vectorului sunt egale.
*/

class Pb1151
{
public:
	int n, v[501];

	bool toateEgale(int st, int dr) {
		if (st == dr)
			return 1;
		if (v[st] != v[dr])
			return 0;
		if (st != dr) {
			int mid = (st + dr) / 2;
			return toateEgale(st, mid) && toateEgale(mid + 1, dr);
		}
	}





	void solve() {
		ifstream fin("Fin.txt");
		fin >> n;
		for (int i = 0; i < n; i++)
			fin >> v[i];
		cout << toateEgale(0, n - 1);
	}
};

