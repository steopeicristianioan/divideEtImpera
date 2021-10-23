#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

using namespace std;

/*
	Un vector de lungime n.

	Plierea vectorului se defineste ca suprapunerea unei jumatati, numite donatoare
	peste cealalta jumatate, numita receptor. Daca numarul de elemente este impar, 
	elementul din mijloc este eliminat. Prin pliere, elementele subvectorului obtinut vor avea
	numerotarea jumatatii receptoare. Plierea se poate aplica repetat, pana cand se ajunge la
	un subvector cu 1 element, numit element final. 
	
	Scrieti un program care sa afiseze toate elementele finale si sa figureze pe ecran pentru 
	fiecare element final o succesiune de plieri.
*/

class Plieri
{
public:

	int n;

	int efinal[100]{};
	
	char m[50][50]{};


	void pliaza(int p, int q) {
		int Ls = 0, Ld = 0, i = 0;

		char ss[50], sd[50], aux[50];



		if (p == q) {
			efinal[p] = 1;

		}
		else {
			if ((q - p + 1) % 2) {

				Ls = (p + q) / 2 - 1;
			}
			else {
				Ls = (p + q) / 2;
			}
			Ld = (p + q) / 2 + 1;



			pliaza(p, Ls);

			_itoa_s(Ls, ss, 10);
			_itoa_s(Ld, sd, 10);
			//cout << ss << " | " << sd << endl;

			for (i = p; i <= Ls; i++) {

				strcpy_s(aux, "S");
				strcat_s(aux, ss);
				strcat_s(aux, " ");
				strcat_s(aux, m[i]);
				strcpy_s(m[i], aux);
			}

			pliaza(Ld, q);

			for (i = Ld; i <= q; i++) {

				strcpy_s(aux, "D");
				strcat_s(aux, sd);
				strcat_s(aux, " ");
				strcat_s(aux, m[i]);
				strcpy_s(m[i], aux);
			}


		}


	}



	void solutie() {

		cout << "n=" << endl;
		cin >> n;
		pliaza(1, n);

		cout << "Elementele finale sunt " << endl;

		for (int i = 1; i <= n; i++) {
			if (efinal[i]) {
				cout << i << ":" << m[i] << endl;
			}
		}

	}







	
	
};

