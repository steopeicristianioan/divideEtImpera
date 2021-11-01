#include <iostream>
#include <fstream>

using namespace std;

class Pb1023
{
public:
	int n, v[101];

	int cmmdcAux(int a, int b) {
		if (!b)
			return a;
		return cmmdcAux(b, a % b);
	}
	int divide(int st, int dr) {
		if (st == dr)
			return v[st];
		else {
			int mid = (st + dr) / 2;
			int left = divide(st, mid);
			int right = divide(mid + 1, dr);
			return cmmdcAux(left, right);
		}
	}
	void solve() {
		ifstream fin("Fin.txt");
		fin >> n;
		for (int i = 0; i < n; i++)
			fin >> v[i];
		cout << divide(0, n - 1);
	}
};

