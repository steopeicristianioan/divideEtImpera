#include <iostream>
#include <fstream>

using namespace std;

/*
	Se considera o tabla dreptunghiulara Lp x Hp
	Se dau n gauri.
	Sa se determine un dreptunghi de arie maxima format prin taieturi prin gauri.
	Tieturile vor fi paralele cu laturile dreptunghiului.
*/

class Taieturi
{
public:
	int n, vx[51]{}, vy[51]{};
	int L, H;
	int aMax = 0, xFin = 0, yFin = 0, lFin = 0, hFin = 0;

	bool inside(int i, int x, int y, int h, int l) {
		return vx[i] >= x && vx[i] < x + h && vy[i] >= y && vy[i] < y + l;
	}
	void taie(int x, int y, int h, int l) {
		//caut gaura
		int i = 1, flag = 0;
		while (i <= n && !flag) {
			if (inside(i, x, y, h, l)) flag++;
			else i++;
		}

		if (flag) { //daca am gasit gaura

			//tai pe orizontala => 2 dreptunghiuri Nord-Sud
			taie(x, y, vx[i] - x, l);
			taie(vx[i] + 1, y, H - vx[i], l);

			//tai pe verticala => 2 dreptunghiuri Est-Vest
			taie(x, y, h, vy[i] - y);
			taie(x, vy[i] + 1, h, L - vy[i]);
			
		}
		else if (l * h > aMax) { //daca nu, compar dimensiunile
			aMax = l * h;
			xFin = x;
			yFin = y;
			lFin = l;
			hFin = h;
		}
	}

	void solve() {
		ifstream fin("Fin.txt");
		fin >> L >> H;
		fin >> n;
		for (int i = 1; i <= n; i++)
			fin >> vx[i] >> vy[i];
		taie(1, 1, L, H);
		cout << "Aria maxima este: " << aMax;
		cout << "\nDescrisa de dreptunghiul cu coltul stanga sus: (" << xFin << "," << yFin << ")";
		cout << "\nDe dimensiune: " << lFin << "x" << hFin;
	}
};

