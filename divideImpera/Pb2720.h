#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

/*
    Metoda Bucket Sort constă în distribuirea 
    elementelor în mai multe grupe, numite “bucket-uri”. 
    Apoi fiecare bucket este sortat individual folosind un algoritm de sortare oarecare.
*/

class Pb2720
{
public:
    int n, d, v[10000];

    bool cmp(int a, int b) {
        if (d) return a > b;
        return a < b;
    }

    void solve() {
        ifstream fin("Fin.txt");
        fin >> n;
        for (int i = 0; i < n; i++)
            fin >> v[i];
        fin >> d;
        //sort(v, v + n, cmp); NU STIU DE CE NU MA LASA SA SCRIU SORT()
        for (int i = 0; i < n; i++)
            cout << v[i] << ' ';
    }
};

