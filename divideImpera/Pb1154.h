#include <iostream>
#include <fstream>

using namespace std;

/*
	Se dă un vector x cu n elemente numere naturale, și un vector y cu m elemente, 
	de asemenea numere naturale. Folosind metoda Divide et Impera, verificați 
	pentru fiecare element al vectorului y dacă apare în x.
*/

class Pb1154
{
public:
	int n, m, x[1001], y[1001];

	bool search(int v) {
		for (int i = 0; i < n; i++)
			if (x[i] == v)
				return true;
		return false;
	}
	void divide(int st, int dr) {
		if (st == dr) {
			cout << search(y[st]) << ' ';
		}
		else {
			int mid = (st + dr) / 2;
			divide(st, mid);
			divide(mid + 1, dr);
		}
	}
	void solve() {
		ifstream fin("Fin.txt");
		fin >> n;
		for (int i = 0; i < n; i++)
			fin >> x[i];
		fin >> m;
		for (int i = 0; i < m; i++)
			fin >> y[i];
		divide(0, m - 1);
	}
};

