#include <iostream>
#include <fstream>

using namespace std;

/*
    Se dă un şir x format din n numere naturale nenule. 
    Pentru fiecare element x[i] din şir să se verifice dacă există un număr k 
    astfel încât elementul x[i] să fie egal cu suma primelor k elemente din şir.
*/

class Pb1865
{
public:
    int n, x;
    long long s[1000001];

    int search(int st, int dr, int x) {
        while (st <= dr) {
            int mid = (st + dr) / 2;
            if (s[mid] == x)
                return mid;
            else if (s[mid] > x)
                dr = mid - 1;
            else st = mid + 1;
        }
        return 0;
    }
    void solve() {
        ifstream fin("Fin.txt");
        fin >> n;
        for (int i = 1; i <= n; i++) {
            fin >> x;
            s[i] = s[i - 1] + x;
            cout << search(1, i, x) << '\n';
        }
    }
};

