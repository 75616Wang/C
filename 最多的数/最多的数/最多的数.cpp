// ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "iostream"
using namespace std;


int main()
{
	int **arr;
	int n = 0;
	int m = 2;
	cout << "���Եĸ���Ϊ:" << endl;
	cin >> n;

	cout << "������"<<n<<"�����֣��ÿո������" << endl;
	for (int i = 0; i < n; i++)
		cin >> arr[0][i];

	for (int i = 0; i < n; i++)
		cout << arr[i] << endl;
	system("pause");
    return 0;
}

