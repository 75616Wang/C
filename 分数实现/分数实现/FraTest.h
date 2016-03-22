#pragma once
#include "iostream"
//交换两个数
void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
//求两个数的最大公约数
int gcd(int a, int b) {
	int t;
	if (a < b) Swap(a, b);
	while (t = a % b) {
		a = b;
		b = t;
	}
	return b;
}
//分数类型，num为分子，den为分母
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
//构造函数，x为分子，y为分母；
Fra::Fra(int x, int y)
{
	num = x;
	den = y;
	Simplify();
}
//构造函数
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


//化简当前分数
void Fra::Simplify()
{
	int c = gcd(num, den);
	if (c != 1)
	{
		num = num / c;
		den = den / c;
	}
}
//将分数强制转换为double类型的小数（可能会造成精度丢失）
double Fra::toDouble()
{
	return (double)num /(double) den;
}
//重载+
Fra operator+(Fra &f1, Fra &f2)
{
	return Fra(f1.num*f2.den + f2.num*f1.den, f1.den*f2.den);
}
//重载-
Fra operator-(Fra &f1, Fra &f2)
{
	return Fra(f1.num*f2.den - f2.num*f1.den, f1.den*f2.den);
}
//重载*
Fra operator*(Fra &f1, Fra &f2)
{
	return Fra(f1.num*f2.num, f1.den*f2.den);
}
//重载/
Fra operator/(Fra&f1, Fra&f2)
{
	return Fra(f1.num*f2.den, f1.den*f2.num);
}

//重载+
Fra operator+(Fra &f1, int a)
{
	Fra f2(a);
	return Fra(f1.num*f2.den + f2.num*f1.den, f1.den*f2.den);
}
//重载-
Fra operator-(Fra &f1, int a)
{
	Fra  f2(a);
	return Fra(f1.num*f2.den - f2.num*f1.den, f1.den*f2.den);
}
//重载*
Fra operator*(Fra &f1, int a)
{
	Fra  f2(a);
	return Fra(f1.num*f2.num, f1.den*f2.den);
}
//重载/
Fra operator/(Fra&f1, int a)
{
	Fra  f2(a);
	return Fra(f1.num*f2.den, f1.den*f2.num);
}


//重载+
Fra operator+(int a, Fra&f1)
{
	Fra f2(a);
	return Fra(f1.num*f2.den + f2.num*f1.den, f1.den*f2.den);
}
//重载-
Fra operator-(int a, Fra&f1)
{
	Fra  f2(a);
	return Fra(f1.num*f2.den - f2.num*f1.den, f1.den*f2.den);
}
//重载*
Fra operator*(int a, Fra&f1)
{
	Fra  f2(a);
	return Fra(f1.num*f2.num, f1.den*f2.den);
}
//重载/
Fra operator/(int a, Fra&f1)
{
	Fra  f2(a);
	return Fra(f1.num*f2.den, f1.den*f2.num);
}



//重载<<
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
//重载>>
std::istream &operator >>(std::istream&is, Fra &f)
{
	is >> f.num;
	return is;
}

