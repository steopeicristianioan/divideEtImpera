#include <iostream>
#include <fstream>

using namespace std;

/*
	Se dă un şir cu n elemente, numere naturale. 
	Folosind metoda Divide et Impera să se verifice dacă toate elementele şirului sunt pare.
*/

class Pb1150
{
public:
	int n, v[101];

	bool toatePare(int st, int dr) {
		if (st == dr) {
			return !(v[st] % 2);
		}
		else {
			int mid = (st + dr) / 2;
			return toatePare(st, mid) && toatePare(mid + 1, dr);
		}
	}
	void solve() {
		ifstream fin("Fin.txt");
		fin >> n;
		for (int i = 0; i < n; i++)
			fin >> v[i];
		cout << toatePare(0, n - 1);
	}
};

