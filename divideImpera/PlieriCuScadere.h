#include <iostream>
#include <fstream>

using namespace std;

/*
	se fac plieri pe un vector astfel:
		din dublul fiecarui element din jum. receptoare se scade elemementul corespunzator
		din jumatatea donatoare.
	Ex: 10 20 30 40 50
	-dupa 1 pliere la stnga avem (-30, 0) //(10 * 2 - 50, 20 * 2 - 40)
	-dupa 1 pliere la dreapta avem (60, 90) //(40 * 2 - 20, 50 * 2 - 10)
*/

class PlieriCuScadere
{
public:
	int n, v[100], aux[100];
	int f[100];

	void pliere(int left, int right) {
		cout << left << " -> " << right << endl;
		for (int i = left; i <= right; i++)
			cout << v[i] << ' ';
		cout << '\n';
		if (left == right)
			f[left] = 1;
		else {
			int mid;
			if ((right - left + 1) % 2)
				mid = (left + right) / 2 - 1;
			else mid = (left + right) / 2;

			for (int i = left; i <= mid; i++)
				v[i] = (2 * v[i]) - v[right - i + 1];

			pliere(left, mid);
		}
	}

	void solve() {
		ifstream fin("Fin.txt");
		fin >> n;
		for (int i = 1; i <= n; i++)
			fin >> v[i], aux[i] = v[i];
		pliere(1, n);
	}
};

