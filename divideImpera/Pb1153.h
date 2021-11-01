#include <iostream>
#include <fstream>

using namespace std;

/*
	Se dă un şir cu n elemente, numere naturale. 
	Folosind metoda Divide et Impera să se verifice dacă toate elementele şirului 
	au număr par de cifre.
*/

class Pb1153
{
public:
	int n, v[101];

	int nrCif(int n) {
		int ct = 0;
		while (n) {
			ct++;
			n /= 10;
		}
		return ct;
	}
	bool toateNrCifPare(int st, int dr) {
		if (st == dr)
			return !(nrCif(v[st]) % 2);
		else {
			int mid = (st + dr) / 2;
			return toateNrCifPare(st, mid) && toateNrCifPare(mid + 1, dr);
		}
	}
	void solve() {
		ifstream fin("Fin.txt");
		fin >> n;
		for (int i = 0; i < n; i++)
			fin >> v[i];
		cout << toateNrCifPare(0, n - 1);
	}
};

