// 最多的数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;


int main()
{
	int **arr;
	int n = 0;
	int m = 2;
	cout << "测试的个数为:" << endl;
	cin >> n;

	cout << "请输入"<<n<<"个数字，用空格隔开：" << endl;
	for (int i = 0; i < n; i++)
		cin >> arr[0][i];

	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;
	system("pause");
    return 0;
}

