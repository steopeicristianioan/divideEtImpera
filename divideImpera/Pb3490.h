#include <iostream>
#include <fstream>

using namespace std;

/*
    Se consideră 2 permutări A şi B ale mulţimii {1, 2, ..., N}. 
    Printr-o operaţie se pot selecta două elemente adiacente din B şi 
    să se interschimbe (i.e. swap(B[i], B[i + 1]) pentru 1 ≤ i < N).
    Să se determine numărul minim de operaţii care trebuiesc 
    efectuate pentru a transforma pe B în A.

    --PROBLEMA DE CONCURS AM FACUT-O DE 100 DE PUNCTE--
*/

class Pb3490
{
public:
    int n;
    int a[100001], b[100001], p[100001];
    int c[100001], inv, temp[100001];

    void sort(int st, int dr) {
        if (st < dr) {
            int mid = (st + dr) / 2;
            sort(st, mid);
            sort(mid + 1, dr);
            int i1 = st, i2 = mid + 1, i = 0;
            while (i1 <= mid && i2 <= dr) {
                if (c[i1] <= c[i2])
                    temp[++i] = c[i1++];
                else {
                    inv += mid - i1 + 1;
                    temp[++i] = c[i2++];
                }
            }
            while (i1 <= mid)
                temp[++i] = c[i1++];
            while (i2 <= dr)
                temp[++i] = c[i2++];
            for (int k = st; k <= dr; k++)
                c[k] = temp[k - st + 1];
        }
    }

    void solve() {
        ifstream fin("Fin.txt");
        fin >> n;
        for (int i = 1; i <= n; i++)
            fin >> a[i], p[a[i]] = i;
        for (int i = 1; i <= n; i++)
            fin >> b[i];
        for (int i = 1; i <= n; i++)
            c[i] = p[b[i]];
        sort(1, n);
        cout << inv;
    }
};

