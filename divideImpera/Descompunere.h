#include <iostream>
#include <fstream>

using namespace std;

/*
	Se da un dreptunghi de dimensiuni a * b;
	Exista 2 moduri de descompunere a acestuia in 2 patrate si 1 dreptunghi.
	Dreptunghiul rezultat se descompune din nou, pana se obtine un dreptunghi nedecompozabil.
	Scrieti un program care determina descompunerea cu un numar minim de figuri componente.
*/

class Descompunere
{
public:
	int a, b;
	int nrMin = INT_MAX, res[101], x[101], l = 0;
	int aFin, bFin;

	void descompunere(int a, int b, int k, int nr_fig) {
		bool ok = false;
		if (a != 1 && b != 1) {
			if (a > (b - a) && b > a) {
				ok = true;
				x[k] = a;
				x[k + 1] = b - a;
				descompunere(a - (b - a), b - a, k + 2, nr_fig + 2);
			}
			if (b > (a / 2)) {
				ok = true;
				x[k] = a / 2;
				descompunere(a, b - (a / 2), k + 1, nr_fig + 2);
			}
		}
		if (!ok) {
			if (nr_fig < nrMin) {
				nrMin = nr_fig;
				l = k;
				for (int i = 1; i < k; i++)
					res[i] = x[i];
				aFin = a;
				bFin = b;
			}
		}
	}

	void solve() {
		ifstream fin("Fin.txt");
		fin >> a >> b;
		descompunere(a, b, 1, 1);
		cout << "Descompunerea cu numar minim de figuri componente are " << nrMin << " figuri.\n";
		cout << "Lungimile laturilor patratelor din descompunere sunt: ";
		for (int i = 1; i < l; i++)
			cout << res[i] << ' ';
		cout << "\nDimensiunea dreptunghiului nedecompozabil ramas este : ";
		cout << bFin << "x" << aFin;
	}
};

