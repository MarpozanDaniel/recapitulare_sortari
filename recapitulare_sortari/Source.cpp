#include <iostream>

using namespace std;

void BubbleSort(int[], int);
void InsertionSort(int[], int);
void SelectionSort(int[], int);
void CountingSort(int[], int);
void CautareBinara(int[], int);
void Interclasare();

int main() {
	int n;
	cout << "Cate elemete are vectorul??"; cin >> n;
	int v[10];
	cout << "Introdu elementele vectorului:" << endl;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	cout << "Vectorul sortat este:" << endl;
	BubbleSort(v, n);
	cout << endl;
	InsertionSort(v, n);
	cout << endl;
	SelectionSort(v, n);
	cout << endl;
	CountingSort(v, n);
	cout << endl;
	CautareBinara(v, n);
	cout << endl;
	Interclasare();
	system("pause");
	return 0; 
}

void BubbleSort(int v[], int n) {
	int ok, i = 0;
	do
	{
		ok = 1;
		for (int j = 0; j < n - i - 1; ++j)
		{
			if (v[j] > v[j + 1])
			{
				swap(v[j], v[j + 1]);
				ok = 0;
			}
		}
		i++;
	} while (ok != 1);
	for (int i = 0; i < n; ++i)
		cout << v[i] << " ";
}

void InsertionSort(int v[], int n)
{
	for (int i = 1; i < n; i++){
		int ind = i - 1;
		int arr = v[i];
		while (v[ind] > arr && ind >= 0) {
			v[ind + 1] = v[ind];
			ind--;
		}
		v[ind + 1] = arr;
	}
	for (int i = 0; i < n; ++i) {
		cout << v[i] << " ";
	}
}

void SelectionSort(int v[], int n) {
	for (int m = n - 1; m >= 0; m--){
		int nmax = v[0];
		int ind = 0;
		for (int i = 0; i <= m; i++){
			if (v[i] > nmax) {
				nmax = v[i];
				ind = i;
			}
		}
		swap(v[m], nmax);
	}
	for (int i = 0; i < n; ++i) {
		cout << v[i] << " ";
	}
}

void CountingSort(int v[], int n) {
	int b[10], c[10];
	for (int i = 0; i < n; i++) {
		b[i] = 0;
		c[i] = v[i];
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v[i] > v[j])
				b[i]++;
			else
				b[j]++;
		}
		for (int i = 0; i < n; ++i) {
			c[b[i]] = v[i];
		}
	}
	for (int i = 0; i < n; i++)
		cout << v[i] << " ";
}

void CautareBinara(int v[], int n) {
	int nr;
	cout << "nr="; cin >> nr;
	int stg = 0;
	int dr = n;
	int ok = 0;
	while (stg <= dr)
	{
		int mij = (stg + dr) / 2;
		if (v[mij] == nr) {
			ok = 1;
			break;
		}
		if (nr >v[mij])
			stg = mij+1;
		if (nr < v[mij])
			dr = mij-1;
	}
	if (ok == 1)
		cout << "Da";
	else
		cout << "Nu";
}

void Interclasare() {
	int a[10], b[10], x, y;
	cout << "Cate elemente are primul vector?"; cin >> x;
	cout << "Introdu elemente primului vector:" << endl;
	for (int i = 0; i < x; ++i)
		cin >> a[i];
	cout << "Cate elemente are cel de-al doilea vector?"; cin >> y;
	cout << "Introdu uelementele vectorului 2:" << endl;
	for (int i = 0; i < y; ++i)
		cin >> b[i];
	int c[20];
	for (int i = 0; i < x + y; i++)
		c[i] = 0;
	int i = 0, j = 0, k = 0;
	while (i < x && j < y) {
		if (a[i] > b[j]) {
			c[k] = b[j];
			k++;
			j++;
		}
		if (a[i] < b[j]) {
			c[k] = a[i];
			k++;
			i++;
		}
	}
	for (int d = i; d < x; d++) {
		c[k] = a[d];
		k++;
	}
	for (int e = j; e < y; e++) {
		c[k] = b[e];
		k++;
	}
	for (int i = 0; i < x + y; i++)
		cout << c[i] << " ";
}