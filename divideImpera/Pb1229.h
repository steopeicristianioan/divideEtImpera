#include <iostream>
#include <fstream>

using namespace std;

class Pb1229
{
public:
    int a[513][513];
    int n, k = 2, ct;

    int pow(int k) {
        if (k == 0)
            return 1;
        else if (k % 2 == 1)
            return 2 * pow(k - 1);
        int p = pow(k / 2);
        return p * p;
    }
    void traversal(int i, int j, int x, int y) {
        if (i == x && j == y)
            cout << a[i][j] << ' ';
        else {
            int iMid = (i + x) / 2;
            int jMid = (j + y) / 2;
            traversal(i, j, iMid, jMid);
            traversal(iMid + 1, jMid + 1, x, y);
            traversal(i, jMid + 1, iMid, y);
            traversal(iMid + 1, j, x, jMid);
        }
    }
    void solve() {
        ifstream fin("Fin.txt");
        int m;
        fin >> m;
        n = pow(m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                fin >> a[i][j];
        traversal(1, 1, n, n);
    }
};

