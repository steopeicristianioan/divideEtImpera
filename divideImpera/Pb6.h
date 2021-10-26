#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std;

class Pb6 ///face figuri de la sort dar merge ca am probat-o pe vs code
{
public:
	int n;
	struct Elev {
		string nume = "";
		string prenume = "";
		double medie = 0.0;
	}v[101];

	bool cmp(Elev e1, Elev e2) {
		return e1.prenume < e2.prenume;
	}
	int binarySearch(string x, int left, int right) {
		if (left > right)
			return 0;
		else {
			int mid = left + right / 2;
			if (v[mid].prenume == x)
				return mid;
			else if (v[mid].prenume < x)
				return binarySearch(x, mid + 1, right);
			else return binarySearch(x, left, mid);
		}
	}
	/*void solve() {
		ifstream fin("Fin.txt");
		fin >> n;
		for (int i = 1; i <= n; i++)
			fin >> v[i].nume >> v[i].prenume >> v[i].medie;
		sort(v + 1, v + n + 1, cmp);
		cout << v[binarySearch("alex", 1, n)].medie;
	}*/
};

