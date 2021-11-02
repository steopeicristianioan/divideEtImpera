#include <iostream>
#include <fstream>

using namespace std;

/*
    Cioc, un elev abia aterizat în clasa a IX-a, primește de la doamna profesor de informatică 
    un șir de n numere naturale pe care trebuie să îl prelucreze. 
    Astfel, băiatul trebuie să scrie după fiecare dintre cele k cele mai mici elemente dublul lor. 
    Dacă cel mai mare dintre aceste numere se repetă și deja se depășesc cele 
    k elemente prevăzute, doamna profesor îi dă libertatea băiatului de a modifica valoarea lui k 
    astfel încât să cuprindă și aceste valori. 
    De exemplu, dacă n = 7, v[] = {1, 4, 6, 2, 3, 4, 5} și k = 4, atunci, \
    în urma prelucrării, șirul v devine {1, 2, 4, 8, 6, 2, 4, 3, 6, 4, 8, 5}, și deci kfinal=5.

    --PROBLEMA DE CONCURS AM FACUT-O DE 100 DE PUNCTE--
*/

class Pb2525
{
public:
    int c, n, k, ct;
    unsigned long long v[100002], aux[100002];

    int partitie(int st, int dr) {
        int pivot = v[dr];
        int j = st;
        for (int i = st; i < dr; i++)
            if (v[i] <= pivot)
                swap(v[i], v[j++]);
        swap(v[j], v[dr]);
        return j;
    }
    void sort(int st, int dr) {
        if (st < dr) {
            int i = partitie(st, dr);
            sort(st, i - 1);
            sort(i + 1, dr);
        }
    }

    void solve() {
        ifstream fin("Fin.txt");
        fin >> c >> n >> k;
        ct = k;
        for (int i = 1; i <= n; i++)
            fin >> v[i], aux[i] = v[i];
        sort(1, n);
        unsigned long long int x = v[k];
        if (c == 1) {
            while (v[++ct] == x);
            cout << --ct;
        }
        else {
            for (int i = 1; i <= n; i++) {
                cout << aux[i] << ' ';
                if (aux[i] <= x)
                    cout << 2 * aux[i] << ' ';
            }
        }
    }
};

