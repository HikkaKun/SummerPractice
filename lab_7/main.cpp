#include <iostream>
#define N 5

using namespace std;

void readarr(int X[N][N])
{
	cout << "¬ведите элементы матрицы:\n";
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> X[i][j];
}

int main()
{
	setlocale(0, "");
	int A[N][N]; int X[N], Y[N];

	readarr(A);
}