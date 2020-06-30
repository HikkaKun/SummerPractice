#include <iostream>
#include <conio.h>

using namespace std;

void readarr(int **X, const int N)
{
	cout << "Введите элементы матрицы:\n";
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> X[i][j];
}

void sort(int **X, const int N)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N-1; j++)
			for (int k = j + 1; k < N; k++)
				if (X[j][i] > X[k][i])
				{
					int t = X[j][i];
					X[j][i] = X[k][i];
					X[k][i] = t;
				}
}

void print(int **A, const int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << A[i][j] << "\t";
		cout << endl;
	}
}

void check(int** A, const int N)
{
	int k = 0;
	for (int i = 0; i < N - 1; i++)
		for (int j = i + 1; j < N; j++)
		{
			while (k < N && A[k][i] == A[k][j])
				k++;
			if (k == N)
				for (int l = 0; l < N; l++)
					A[l][j] = 0;
			k = 0;
		}
}

int main()
{
	setlocale(0, "");

	int N, ** p;
	cout << "Введите размер матрицы:\n";
	cin >> N;
	p = new int* [N];
	for (int i = 0; i < N; i++)
		p[i] = new int[N];
	readarr(p, N);
	cout << "Исходная матрица:\n";
	print(p, N);
	sort(p, N);
	cout << "Отсортированная матрица:\n";
	print(p, N);
	check(p, N);
	cout << "Матрица после удаления дубликатов столбцов:\n";
	print(p, N);

	_getch();
}