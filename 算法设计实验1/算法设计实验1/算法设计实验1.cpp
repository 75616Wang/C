// 算法设计实验1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include "DC.h"
using namespace std;

int main()
{
	int arr[5] = { 32,23,42,14,25 };
	SortList<int>L(5, arr);
	L.show();
	L.Sort(1, 3);
	L.show();
	system("pause");
    return 0;
}

