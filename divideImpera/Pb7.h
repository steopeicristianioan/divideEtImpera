#include <fstream>
#include <iostream>

using namespace std;

class Pb7
{
public:
	int n, a[101][101]{};
	int Amax = -1, lMax = -1, ct = 0, v = 0;
	int xs = -1, ys = -1;

	void update(int i, int j, int x, int y) {
		if ((x - i) + 1 * (x-i) + 1 > Amax && ct) {
			Amax = (x - i) + 1 * (x - i) + 1;
			lMax = (x - i) + 1;
			xs = i;
			ys = j;
			v = ct;
		}
	}
	void divide(int k, int i, int j, int x, int y) {
		if (i == x && j == y) {
			//cout << i << " " << j << " " << x << " " << y << " - ";;
			if (a[i][j] == 1)
				ct++;
			//cout << ct << '\n';
		}
		else {
			int iMid = (i + x) / 2;
			int jMid = (j + y) / 2;
			divide(k+1, i, j, iMid, jMid);
			divide(k+1, i, jMid + 1, iMid, y);
			divide(k+1, iMid + 1, j, x, jMid);
			divide(k+1, iMid + 1, jMid + 1, x, y);
			if (ct % 2 == 0)
				update(i, j, x, y);
			if(k == 1) ct = 0;
		}
	}
	void solve() {
		ifstream fin("Fin.txt");
		fin >> n;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				fin >> a[i][j];
		divide(0, 1, 1, n, n);
		cout << xs << "," << ys;
		cout << '\n' << lMax;
	}
};

