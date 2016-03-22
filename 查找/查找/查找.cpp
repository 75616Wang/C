// 查找.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"iostream"
using namespace std;
int b_search(int *p, int l, int r, int key) {
	int f, m;
	m = (l + r) / 2;
	if (l>r)
		f = -1;
	else if (p[m] == key)
		f = m;
	else if (p[m]>key)
		f = b_search(p, l, r - 1, key);
	else
		f = b_search(p, l + 1, r, key);
	return f;
}
int main() {
	int a[10] = { 10,20,25,30,40,50,60,70,80,90 };
	int p, k;
	while (true)
	{
		cout << "input k:";
		cin >> k;
		p = b_search(a, 0, 6, k);
		if (p >= 0)
			cout << "found:" << k << "=a[" << p << "]" << endl;
		else
			cout << "no found:" << k << endl;
	}
	return 0;
}