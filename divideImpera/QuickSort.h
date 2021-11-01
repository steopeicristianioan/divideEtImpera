#include <iostream>
#include <fstream>

using namespace std;

class QuickSort
{
public:
	int n, v[101]{};



	void swap(int& i, int& j) {
		int aux = i;
		i = j;
		j = aux;
	}

	int partitie(int st, int dr){
		int pivot = v[dr];
		int index = st;
		for (int i = st; i < dr; i++) {
			if (v[i] <= pivot) {
				swap(v[i], v[index]);
				index++;
			}
		}

		swap(v[index], v[dr]);

		return index;
	}


	void quickSort(int st, int dr) {
		if (st < dr) {
			int index = partitie(st, dr);
			quickSort(st, index - 1);
			quickSort(index + 1, dr);
		}
	}

	void solve() {
		ifstream fin("Fin.txt");
		fin >> n;
		for (int i = 0; i < n; i++)
			fin >> v[i];
		
		quickSort(0, n - 1);

	
	

		for (int i = 0; i < n; i++)
			cout << v[i] << ' ';
	}
};

