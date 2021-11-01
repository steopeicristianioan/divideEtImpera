#include <iostream>
#include <fstream>

using namespace std;

class KthMin
{
public:
	int n, k, v[101];

	int partitie(int st, int dr) {
		int p = v[dr];
		int j = st;
		for (int i = st; i < dr; i++)
			if (v[i] <= p)
				swap(v[i], v[j++]);
		swap(v[j], v[dr]);
		return j;
	}
	void sort(int st, int dr) {
		if (st < dr && dr >= k - 1) {
			int index = partitie(st, dr);
			sort(st, index - 1);
			sort(index + 1, dr);
		}
	}
	void solve() {
		ifstream fin("Fin.txt");
		fin >> n >> k;
		for (int i = 0; i < n; i++)
			fin >> v[i];
		sort(0, n - 1);
		cout << v[k - 1] << endl;
		for (int i = 0; i < n; i++)
			cout << v[i] << ' ';
	}
};

