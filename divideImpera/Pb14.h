#include <iostream>
#include <fstream>

using namespace std;

class Pb14
{
public:
	int n, a[251][251];

	void divide(int i, int j, int x, int y) {
		///trebuie sa apelez divide de 9 ori????
	}

	void solve() {
		ifstream fin("Fin.txt");
		fin >> n;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				fin >> a[i][j];
	}
};

