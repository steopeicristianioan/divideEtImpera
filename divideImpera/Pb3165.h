#include <iostream>
#include <fstream>

using namespace std;

/*
	Se consideră o matrice cu m linii și n coloane, numere naturale. 
	Folosind metoda Divide et Impera, determinați suma numerelor pare din matrice.
*/

class Pb3165
{
public:
	int n, m, a[101][101];

	long long sCol(int col) {
		long long s = 0;
		for (int i = 1; i <= n; i++)
			if (a[i][col] % 2 == 0)
				s += a[i][col];
		return s;
	}
	long long sum(int i, int j, int x, int y) {
		if (j == y) 
			return sCol(j);
		else{
			int jMid = (j + y) / 2;
			return sum(i, j, x, jMid) + sum(i, jMid + 1, x, y);
		}
	}
	void solve() {
		ifstream fin("Fin.txt");
		fin >> n >> m;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				fin >> a[i][j];
		for (int i = 1; i <= n; i++, cout << '\n')
			for (int j = 1; j <= m; j++)
				cout << a[i][j] << ' ';
		cout << sum(1, 1, n, m);
	}
};

