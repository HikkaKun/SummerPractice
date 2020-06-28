#include <iostream>
#include <fstream>
#include <conio.h>
#define N 5

using namespace std;

void readarr(int X[N][N])
{
	cout << "Введите элементы матрицы:\n";
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> X[i][j];
}

void filearr(int X[N][N])
{
	ifstream file ("in.txt");
	if (file)
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				file >> X[i][j];
	}
	else
	{
		cout << "Входной файл отсутсвует\n";
		exit;
	}
	file.close();
}

int* mas_x(int(*A)[N], int* X,
	void (*pfunc)(int[N][N]))
{
	pfunc(A);
	int k = 0, next, cur, end = 1;
	for (int i = 0; i < N*N - 1; i++)
	{
		cur = A[i / 5][i % 5];
		next = A[(i+1) / 5][(i+1) % 5];
		switch (k)
		{
		case 0: if (cur < next) k = 1; if (cur > next) k = 2; break;
		case 1: if (cur > next) end = -1; break;
		case 2: if (cur < next) end = -1;
		}
	}
	for (int i = 0; i < N; i++)
		X[i] = end;
	return X;
}

void output(const int X[], const int A[][N])
{
	cout << "Матрица A:\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << A[i][j] << "\t";
		cout << endl;
	}
	cout << "Массив X:\n";
	for (int i = 0; i < N; i++)
		cout << X[i] << "\t";
}

int main()
{
	setlocale(0, "");
	int A[N][N]; int X[N], c, y;

	void (*pfunc) (int [N][N]);
	do
	{
		cout << "Ввод матрицы:\n1 - с клавиатуры\n2 - из файла\n";
		cin >> c;
	} while (c != 1 && c != 2);

	if (c == 1) pfunc = &readarr;
	else pfunc = &filearr;

	output(mas_x(A, X, pfunc), A);
	_getch();
}