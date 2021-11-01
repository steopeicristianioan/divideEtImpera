#include <iostream>
#include <fstream>

using namespace std;

class Pb1020
{
public:
	int n, v[1001];
	int maxi = 0;

	bool prim(int value) {
		if (!value || value == 1)
			return 0;
		if (value % 2 == 0 && value != 2)
			return 0;
		for (int i = 3; i * i <= value; i++)
			if (value % i == 0)
				return 0;
		return 1;
	}
	void getMaxPrim(int st, int dr) {
		if (st == dr) {
			if (prim(v[st]) && v[st] > maxi)
				maxi = v[st];
		}
		else
		{
			int mid = (st + dr) / 2;
			getMaxPrim(st, mid);
			getMaxPrim(mid + 1, dr);
		}
	}
	void solve() {
		ifstream fin("Fin.txt");
		fin >> n;
		for (int i = 0; i < n; i++)
			fin >> v[i];
		getMaxPrim(0, n - 1);
		cout << maxi;
	}
};

