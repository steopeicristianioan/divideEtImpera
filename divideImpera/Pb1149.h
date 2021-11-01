#include <iostream>
#include <fstream>

using namespace std;

/*
	Se dă un şir cu n elemente, numere naturale. 
	Folosind metoda Divide et Impera să se verifice dacă în şir există elemente prime.
*/

class Pb1149
{
public:
	int n, v[201], nMax = 10000;
	int ciur[10000]{};

	void makeCiur() {
		ciur[0] = 1;
		ciur[1] = 1;
		for(int i = 2; i*i <= nMax; i++)
			if (!ciur[i]) {
				for (int j = 2; j <= nMax / i; j++)
					ciur[i * j]++;
			}
		cout << "DONE\n";
	}
	bool divide(int st, int dr) {
		if (st == dr) {
			return !ciur[v[st]];
		}
		else {
			int mid = (st + dr) / 2;
			return divide(st, mid) || divide(mid + 1, dr);
		}
	}
	void solve() {
		ifstream fin("Fin.txt");
		fin >> n;
		for (int i = 0; i < n; i++)
			fin >> v[i];
		makeCiur();
		cout << divide(0, n-1);
	}
};

