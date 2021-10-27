#include <iostream>
#include <fstream>

using namespace std;

class Pb13
{
public:
	int n, v[101], temp[101];

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
		fin >> n;
		for (int i = 1; i <= n; i++)
			fin >> v[i];
		mergeSort(1, n);
		cout << v[1] << ' ';
		for (int i = 2; i < n; i += 2)
			cout << v[i + 1] << ' ' << v[i] << ' ';
	}
};

