// 模板类实现栈.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#define SIZE 10;
using namespace std;

template<class T>
class Stack
{
public:
	Stack();
	~Stack();
	bool IsEmpty();
	bool IsFull();
	void push(T t);
	T pop();

private:
	T x[SIZE];
	int top;
};
template<class T>
Stack<T>::Stack()
{
	top = -1;
}
template<class T>
Stack<T>::~Stack()
{
}
template<class T>
bool Stack<T>::IsEmpty()
{
	return top == -1;
}
template<class T>
bool Stack<T>::IsFull()
{
	return top == SIZE - 1;
}
template<class T>
void Stack<T>:: push(T t)
{
	if (top==SIZE-1)
	{
		cout << "Stack is full!!!" << ensl;
	}
	else
	{
		x[++top] = t;
	}
}
template <class T>
T Stack<T>::pop()
{
	if (top==-1)
	{
		cout << "Stack is empty!!!" << endl;
		return 0;
	}
	else
	{
		return x[top--];
	}
}

int main()
{
	Stack<int>a;
	Stack<string>b;

    return 0;
}

