#include <iostream>
#include <fstream>

using namespace std;

class Pb1019
{
public:
	int n, v[1001], maxi = 0;

	void getMax(int st, int dr) {
		if (st == dr) {
			if (v[st] > maxi)
				maxi = v[st];
		}
		else {
			int mid = (st + dr) / 2;
			getMax(st, mid);
			getMax(mid + 1, dr);
		}
	}
	void solve() {
		ifstream fin("Fin.txt");
		fin >> n;
		for (int i = 0; i < n; i++)
			fin >> v[i];
		getMax(0, n - 1);
		cout << maxi;
	}
};

