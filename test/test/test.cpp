// test.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "iostream"
#include "iomanip"
using namespace std;
int main()
{
	long double a = 1000000000000000000;
	long double b = 3;
	long double c = a / b;
	cout << setprecision(20) << c << endl;
	system("pause");
    return 0;
}

