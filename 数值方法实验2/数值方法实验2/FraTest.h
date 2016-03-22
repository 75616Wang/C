#pragma once
#include "iostream"
//����������
void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
//�������������Լ��
int gcd(int a, int b) {
	int t;
	if (a < b) Swap(a, b);
	while (t = a % b) {
		a = b;
		b = t;
	}
	return b;
}
//�������ͣ�numΪ���ӣ�denΪ��ĸ
class Fra
{
public:
	Fra(int x, int y);
	Fra(int x);
	Fra();
	void Simplify();
	
	double toDouble();
	~Fra();

	int num;
	int den;
};
//���캯����xΪ���ӣ�yΪ��ĸ��
Fra::Fra(int x, int y)
{
	num = x;
	den = y;
	Simplify();
}
//���캯��
Fra::Fra(int x)
{
	num = x;
	den = 1;
}
Fra::Fra()
{
	den = 1;
	num = 0;
}
Fra::~Fra()
{
}


//����ǰ����
void Fra::Simplify()
{
	int c = gcd(num, den);
	if (c != 1)
	{
		num = num / c;
		den = den / c;
	}
}
//������ǿ��ת��Ϊdouble���͵�С�������ܻ���ɾ��ȶ�ʧ��
double Fra::toDouble()
{
	return (double)num /(double) den;
}
//����+
Fra operator+(Fra &f1, Fra &f2)
{
	return Fra(f1.num*f2.den + f2.num*f1.den, f1.den*f2.den);
}
//����-
Fra operator-(Fra &f1, Fra &f2)
{
	return Fra(f1.num*f2.den - f2.num*f1.den, f1.den*f2.den);
}
//����*
Fra operator*(Fra &f1, Fra &f2)
{
	return Fra(f1.num*f2.num, f1.den*f2.den);
}
//����/
Fra operator/(Fra&f1, Fra&f2)
{
	return Fra(f1.num*f2.den, f1.den*f2.num);
}

//����+
Fra operator+(Fra &f1, int a)
{
	Fra f2(a);
	return Fra(f1.num*f2.den + f2.num*f1.den, f1.den*f2.den);
}
//����-
Fra operator-(Fra &f1, int a)
{
	Fra  f2(a);
	return Fra(f1.num*f2.den - f2.num*f1.den, f1.den*f2.den);
}
//����*
Fra operator*(Fra &f1, int a)
{
	Fra  f2(a);
	return Fra(f1.num*f2.num, f1.den*f2.den);
}
//����/
Fra operator/(Fra&f1, int a)
{
	Fra  f2(a);
	return Fra(f1.num*f2.den, f1.den*f2.num);
}


//����+
Fra operator+(int a, Fra&f1)
{
	Fra f2(a);
	return Fra(f1.num*f2.den + f2.num*f1.den, f1.den*f2.den);
}
//����-
Fra operator-(int a, Fra&f1)
{
	Fra  f2(a);
	return Fra(f1.num*f2.den - f2.num*f1.den, f1.den*f2.den);
}
//����*
Fra operator*(int a, Fra&f1)
{
	Fra  f2(a);
	return Fra(f1.num*f2.num, f1.den*f2.den);
}
//����/
Fra operator/(int a, Fra&f1)
{
	Fra  f2(a);
	return Fra(f1.num*f2.den, f1.den*f2.num);
}



//����<<
std::ostream &operator<<(std::ostream&os, Fra &f)
{
	if (f.den == 1)
	{
		os << f.num;
		return os;
	}
	os << f.num << "/" << f.den;
	return os;
}
//����>>
std::istream &operator >>(std::istream&is, Fra &f)
{
	is >> f.num;
	return is;
}

