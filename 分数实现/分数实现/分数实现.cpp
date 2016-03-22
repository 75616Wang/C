// 分数实现.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "FraTest.h"
#include "iomanip"
using namespace std;

int main()
{
	Fra a = 3;
	cout << "a=" << a << endl;
	cout << "a=" <<setprecision(20)<< a.toDouble() << endl;

	Fra a1(1, 3);
	cout << "a1=" << a1 << endl;
	cout << "a1=" << setprecision(20) << a1.toDouble() << endl;

	cout << "a+a1=" << a+a1 << endl;
	cout << "a+a1=" << setprecision(20) << (a+a1).toDouble() << endl;

	Fra f2;
	cout << f2;
	cin >> f2;
	cout << f2 << endl;
	system("pause");
    return 0;
}

