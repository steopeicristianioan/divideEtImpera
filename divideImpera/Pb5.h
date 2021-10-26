#include <iostream>
#include <fstream>

using namespace std;

class Pb5
{
public:
	int n, a[101][101]{};
	int ct = 0;

	void divide(int k, int i, int j, int x, int y) {
		if (i == x && j == y) {
			if (a[i][j] == k)
				ct++;
		}
		else {
			int iMid = (i + x) / 2;
			int jMid = (j + y) / 2;
			divide(k, i, j, iMid, jMid);
			divide(k, i, jMid + 1, iMid, y);
			divide(k, iMid + 1, j, x, jMid);
			divide(k, iMid + 1, jMid + 1, x, y);
		}
	}

	void solve() {
		ifstream fin("Fin.txt");
		fin >> n;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				fin >> a[i][j];
		divide(0, 1, 1, n, n);
		cout << ct;
	}
};

