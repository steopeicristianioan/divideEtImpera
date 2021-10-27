#include <iostream>
#include <fstream>

using namespace std;

class Pb10
{
public:
	int n, v[101], ct = 0;

	int cntBaza2(int n) {
		int ct = 0;
		while (n) {
			if (n % 2 == 1)
				ct++;
			n /= 2;
		}
		return ct;
	}
	void divide(int x, int st, int dr) {
		if (st == dr) {
			if (cntBaza2(v[st]) == x)
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
		divide(1, 1, n);
		cout << ct;
	}
};

