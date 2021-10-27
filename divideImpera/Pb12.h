#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Pb12
{
public:
	int n, rez[101];

	struct Elev {
		int index = 0;
		string nume = "";
		string prenume = "";
		double medie = 0.0;
	}v[101], temp[101];

	void sort(int st, int dr) {
		if (st < dr) {
			int mid = (st + dr) / 2;
			sort(st, mid);
			sort(mid + 1, dr);
			int i1 = st, i2 = mid + 1, d = 0;
			while (i1 <= mid && i2 <= dr) {
				if (v[i1].medie <= v[i2].medie)
					temp[++d] = v[i1++];
				else temp[++d] = v[i2++];
			}
			while (i1 <= mid)
				temp[++d] = v[i1++];
			while (i2 <= dr)
				temp[++d] = v[i2++];
			for (int i = st; i <= dr; i++)
				v[i] = temp[i - st + 1];
		}
	}

	void solve() {
		ifstream fin("Fin.txt");
		fin >> n;
		for (int i = 1; i <= n; i++)
			v[i].index = i, fin >> v[i].nume >> v[i].prenume >> v[i].medie;
		sort(1, n);
		for (int i = 1; i <= n; i++)
			cout << v[i].prenume << '\n';
	}
};

