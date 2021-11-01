#include <iostream>
#include <fstream>

using namespace std;

/*
	Daca exista elem impare in sir
*/

class Pb1148
{
public: 
	int n, v[1001];

	bool exista(int st, int dr) {
		if (st == dr)
			return v[st] % 2;
		else {
			int mid = (st + dr) / 2;
			return exista(st, mid) || exista(mid + 1, dr);
		}
	}
	void solve() {
		ifstream fin("Fin.txt");
		fin >> n;
		for (int i = 1; i <= n; i++)
			fin >> v[i];
		cout << exista(1, n);
	}
};

