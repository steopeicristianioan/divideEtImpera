#include <iostream>
#include <fstream>

using namespace std;

class Pb1152
{
public:
	int n, v[501];

	bool ordonat(int st, int dr) {
		if (st == dr)
			return 1;
		if (v[st] > v[dr])
			return 0;
		if (st < dr) {
			int mid = (st + dr) / 2;
			return ordonat(st, mid) && ordonat(mid + 1, dr);
		}
	}
	void solve() {
		ifstream fin("Fin.txt");
		fin >> n;
		for (int i = 0; i < n; i++)
			fin >> v[i];
		cout << ordonat(0, n - 1);
	}
};

