#include <iostream>
#include <fstream>

using namespace std;

class TowerOfHanoi
{
public:
	int n;
	
	void hanoi(int n, char a, char b, char c) {
		if (n > 0) {
			hanoi(n - 1, a, c, b);
			cout << a << "->" << c << '\n';
			hanoi(n - 1, b, a, c);
		}
	}
	void solve() {
		ifstream fin("Fin.txt");
		fin >> n;
		hanoi(n, 'A', 'B', 'C');
	}
};

