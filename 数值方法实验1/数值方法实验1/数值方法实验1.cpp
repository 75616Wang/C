// 数值计算方法实验一.cpp : 定义控制台应用程序的入口点。
//方程求根

#include "stdafx.h"
#include "iostream"
#include "iomanip"
#include "Method.h"
int main()
{
	//cout 默认输出6位小数，可用cout << setprecision(n) << x；扩展，n为小数位数
	cout << "二分法计算结果：" << endl;
	cout << setprecision(10) << dichotomy(1, 2) << endl;
	cout << "迭代法计算结果：" << endl;
	cout << setprecision(10) << iterative(1.5) << endl;
	cout << "牛顿法计算结果：" << endl;
	cout << setprecision(10) << nfunction(1.5) << endl;
	cout << "割线法计算结果：" << endl;
	cout << setprecision(10) << secantM(1, 2) << endl;
	system("pause");
	return 0;
}