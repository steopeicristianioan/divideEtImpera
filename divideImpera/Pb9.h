#include <iostream>
#include <fstream>

using namespace std;

class Pb9
{
public:
	int n, v[101], ct = 0;

	void divide(int x, int st, int dr) {
		if (st == dr) {
			if (v[st] > x)
				ct++;
		}
		else {
			int mid = (st + dr) / 2;
			divide(x, st, mid);
			divide(x, mid + 1, dr);
		}
	}
	void solve() {
		ifstream fin("Fin.txt");
		fin >> n;
		for (int i = 1; i <= n; i++)
			fin >> v[i];
		divide(2, 1, n);
		cout << ct;
	}
};

