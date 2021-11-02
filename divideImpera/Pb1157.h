#include <iostream>
#include <fstream>

using namespace std;

/*
    Se dă un vector cu n elemente, numere naturale și un număr k. 
    Ordonați crescător primele k elemente ale vectorului 
    și descrescător ultimele n-k elemente.
*/

class Pb1157
{
public:
    int n, k, v[200001];

    int partitie(int st, int dr, bool cresc) {
        int piv = v[dr];
        int j = st;
        for (int i = st; i < dr; i++) {
            if (cresc && v[i] <= piv)
                swap(v[i], v[j++]);
            if (!cresc && v[i] >= piv)
                swap(v[i], v[j++]);
        }
        swap(v[j], v[dr]);
        return j;
    }
    void quick(int st, int dr, bool cresc) {
        if (st < dr) {
            int index = partitie(st, dr, cresc);
            quick(st, index - 1, cresc);
            quick(index + 1, dr, cresc);
        }
    }

    void solve() {
        ifstream fin("Fin.txt");
        fin >> n >> k;
        for (int i = 0; i < n; i++)
            fin >> v[i];
        quick(0, k - 1, 1);
        quick(k, n - 1, 0);
        for (int i = 0; i < n; i++)
            cout << v[i] << ' ';
    }
};

