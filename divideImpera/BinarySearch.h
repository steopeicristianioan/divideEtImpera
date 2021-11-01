#include <iostream>
#include <fstream>

using namespace std;

class BinarySearch
{
public:
	int n, k, v[101];

	int search(int st, int dr) {
		if (st > dr)
			return -1;
		if (st <= dr){
			int mid = (st + dr) / 2;
			if (v[mid] == k)
				return mid;
			else if (v[mid] > k)
				return search(st, mid);
			else return search(mid + 1, dr);
		}
	}

	void solve() {
		ifstream fin("Fin.txt");
		fin >> n >> k;
		for (int i = 1; i <= n; i++)
			fin >> v[i];
		cout << search(1, n);
	}
};

