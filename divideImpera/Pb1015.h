#include <iostream>
#include <fstream>

using namespace std;

/*
	Suma vec de dim n
*/

class Pb1015
{
public:
	int n, v[1001];

	int sum(int st, int dr) {
		if (st > dr)
			return 0;
		else if (st == dr)
			return v[st];
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

