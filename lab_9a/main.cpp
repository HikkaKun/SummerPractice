#include <iostream>
#include <conio.h>

using namespace std;

void readarr(int **X, int N)
{
	cout << "¬ведите элементы матрицы:\n";
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> X[i][j];
}

int main()
{
	setlocale(0, "");
	int N, ** p;
	cout << "¬ведите размер массива:\n";
	cin >> N;
	p = new int* [N];
	for (int i = 0; i < N; i++)
		p[i] = new int[N];

	readarr(p, N);

	_getch();
}