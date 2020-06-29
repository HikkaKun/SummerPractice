#include <iostream>
#include <conio.h>

using namespace std;

void readarr(int **X, const int N)
{
	cout << "������� �������� �������:\n";
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

int main()
{
	setlocale(0, "");

	int N, ** p;
	cout << "������� ������ �������:\n";
	cin >> N;
	p = new int* [N];
	for (int i = 0; i < N; i++)
		p[i] = new int[N];
	readarr(p, N);
	cout << "�������� �������:\n";
	print(p, N);
	sort(p, N);
	cout << "��������������� �������:\n";
	print(p, N);

	_getch();
}