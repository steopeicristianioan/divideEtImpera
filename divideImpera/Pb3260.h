#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

using namespace std;

/*
    Se dă funcția f(x)=sin(x)+sin(2∗x)+x și o valoare y. 
    Știind că funcția este strict crescătoare pe intervalul [0,1), 
    se cere să se gasească pentru ce x∈[0,1) avem că f(x)≈y (aproximare cu 8 zecimale).
*/

class Pb3260
{
public:
    double y, eps = 0.000000001;

    double f(double x) {
        return sin(x) + sin(2 * x) + x;
    }
    double search(double st, double dr) {
        if (st <= dr) {
            double mid = (st + dr) / 2;
            double v = f(mid);
            if (abs(y - v) < eps)
                return mid;
            else if (v > y)
                return search(st, mid);
            return search(mid, dr);
        }
    }
    void solve() {
        ifstream fin("Fin.txt");
        fin >> y;
        cout << fixed << setprecision(8) << search(0, 1);
    }
};

