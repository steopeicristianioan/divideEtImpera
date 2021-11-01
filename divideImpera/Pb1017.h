#include <iostream>
#include <fstream>

using namespace std;

class Pb1017
{
public:
	int n, v[1001];

	int sum(int st, int dr) {
		if (st == dr) {
			if (v[st] % 2 == 0)
				return v[st];
			else return 0;
		}
		else {
			int mid = (st + dr) / 2;
			return sum(st, mid) + sum(mid + 1, dr);
		}
	}
	void solve() {
		ifstream fin("Fin.txt");
		fin >> n;
		for (int i = 1; i <= n; i++)
			fin >> v[i];
		cout << sum(1, n);
	}
};

