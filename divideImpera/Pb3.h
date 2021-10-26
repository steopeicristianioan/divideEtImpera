#include <iostream>
#include <fstream>

using namespace std;

/*
	de cate ori apare x in v de dimensiune n
*/

class Pb3
{
public:
	int x, n, v[101], ct = 0;

	int divide(int st, int dr) {
		if (st == dr) {
			if (v[st] == x)
				return 1;
			else return 0;
		}
		else {
			int mid = (st + dr) / 2;
			return divide(st, mid) + divide(mid + 1, dr);
		}
	}

	void solve() {
		ifstream fin("Fin.txt");
		fin >> x >> n;
		for (int i = 1; i <= n; i++)
			fin >> v[i];
		cout << divide(1, n);
	}
};

