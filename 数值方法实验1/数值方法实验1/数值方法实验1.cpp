// ��ֵ���㷽��ʵ��һ.cpp : �������̨Ӧ�ó������ڵ㡣
//�������

#include "stdafx.h"
#include "iostream"
#include "iomanip"
#include "Method.h"
int main()
{
	//cout Ĭ�����6λС��������cout << setprecision(n) << x����չ��nΪС��λ��
	cout << "���ַ���������" << endl;
	cout << setprecision(10) << dichotomy(1, 2) << endl;
	cout << "��������������" << endl;
	cout << setprecision(10) << iterative(1.5) << endl;
	cout << "ţ�ٷ���������" << endl;
	cout << setprecision(10) << nfunction(1.5) << endl;
	cout << "���߷���������" << endl;
	cout << setprecision(10) << secantM(1, 2) << endl;
	system("pause");
	return 0;
}