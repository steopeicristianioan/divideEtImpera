#include <iostream>
#include <fstream>

using namespace std;

/*
    Se dă șirul a1, a2, …, an care este o permutare a mulțimii {1, 2, ..., n}. 
    O inversiune în permutare este o pereche (i, j) cu proprietatea că i < j și a[i] > a[j].
    Să se determine numărul inversiunilor permutării.

    Am facut-o in O(N*logN)
*/

class Pb3206
{
public:
    int n, a[100001], temp[100001];
    long long ct;

    void mergeSort(int st, int dr) {
        if (st < dr) {
            int mid = (st + dr) / 2;
            mergeSort(st, mid);
            mergeSort(mid + 1, dr);
            int i1 = st, i2 = mid + 1, i = 0;
            while (i1 <= mid && i2 <= dr) {
                if (a[i1] <= a[i2])
                    temp[++i] = a[i1++];
                else {
                    ct += mid - i1 + 1;
                    temp[++i] = a[i2++];
                }
            }
            while (i1 <= mid)
                temp[++i] = a[i1++];
            while (i2 <= dr)
                temp[++i] = a[i2++];
            for (int k = st; k <= dr; k++)
                a[k] = temp[k - st + 1];
        }
    }

    void solve() {
        ifstream fin("Fin.txt");
        fin >> n;
        for (int i = 1; i <= n; i++)
            fin >> a[i];
        mergeSort(1, n);
        cout << ct;
    }
};

