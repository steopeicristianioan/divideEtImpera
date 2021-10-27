#include <iostream>
#include <fstream>

using namespace std;

class Pb11
{
public:
	int n, v[101], g, temp[101];

	void mergeSort(int st, int dr) {
		if (st >= dr)
			return;
		else {
			int mid = (st + dr) / 2;
			mergeSort(st, mid);
			mergeSort(mid + 1, dr);
			int i1 = st, i2 = mid + 1, d = 0;
			while (i1 <= mid && i2 <= dr) { ///interclasare
				if (v[i1] <= v[i2])
					temp[++d] = v[i1++];
				else temp[++d] = v[i2++];
			}
			while (i1 <= mid)
				temp[++d] = v[i1++];
			while (i2 <= dr)
				temp[++d] = v[i2++];
			for (int i = st; i <= dr; i++) ///punere inapoi in vectorul dat
				v[i] = temp[i - st + 1];
		}
	}

	void solve() {
		ifstream fin("Fin.txt");
		fin >> n >> g;
		for (int i = 1; i <= n; i++)
			fin >> v[i];
		mergeSort(1, n);
		int rez = 0, s = 0;
		for (int i = 1; i < n && s + v[i] <= g; i++)
			rez++, s += v[i];
		cout << rez;
	}
};

