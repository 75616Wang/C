//LU�ֽⷨ
#pragma once
#include "iostream"
using namespace std;
class Equations
{
public:
	Equations();
	Equations(double arr[3][4]);
	void solve();
	void show();
	void solveL(int i, int j);
	void solveU(int i, int j);
	~Equations() {};
private:
	double equation[3][4];
	double L[3][3];
	double U[3][3];
	double *SOLVE;
};
Equations::Equations()
{

}
Equations::Equations(double arr[3][4])
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++)
			equation[i][j] = arr[i][j];
	for (int i = 0; i < 3; i++)
	{
		for (int j = i; j < 3; j++)
		{
			
			solveU(i, j);
			solveL(j, i);
			//show();
		}
	}
}
void Equations::solveL(int x, int y)
{
	if (x == y) { L[x][y] = 1; return; }
	if (y == 0)
	{
		L[x][y] = equation[x][0] / U[0][0]; return;
	}
	double temp = 0;
	for (int i = 0; i < y - 1; i++)
	{
		temp = temp + L[x][i] * U[i][y];
	}
	L[x][y] = (equation[x][y] - temp) / U[y][y];
}
void Equations::solveU(int x, int y)
{
	if (x == 0)
	{
		U[x][y] = equation[x][y];
		return;
	}
	double temp = 0;
	for (int i = 0; i < x - 1; i++)
	{
		temp = temp + L[x][i] * U[i][y];
	}
	U[x][y] = equation[x][y] - temp;
}
void Equations::solve()
{

}
void Equations::show()
{
	cout << "equation:" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << equation[i][j] << "\t";
		cout << endl;
	}
	cout << "L:" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << L[i][j] << "\t";
		cout << endl;
	}
	cout << "U:" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << U[i][j] << "\t";
		cout << endl;
	}
	cout << endl;
}