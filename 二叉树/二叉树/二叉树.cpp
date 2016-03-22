#include "stdafx.h"
#include <iostream> 
#include <stack>
using namespace std;
typedef char TElemType;
typedef struct BiTNode
{
	TElemType data;
	BiTNode *lchild, *rchild;
}*BiTree;
void visit(TElemType a)
{
	cout<< a;
}
void CreateBiTree(BiTree &T, char a[], int &i) {
	i++;
	if (a[i] == '.') {
		T = NULL;   return;
	}
	T = new BiTNode;
	T->data = a[i];
	CreateBiTree(T->lchild, a, i);
	CreateBiTree(T->rchild, a, i);
}
void CreateBiTree(BiTree &T, char a[])//���������� 
{
	int i = -1;
	CreateBiTree(T, a, i);
}
void display(BiTree T)
{
	if (!T)
	{
		cout << "^";
		return;
	}
	cout << T->data;
	if (T->lchild || T->rchild)
	{
		cout << "(";
		display(T->lchild);
		cout << "^";
		display(T->rchild);
		cout << ")";

	}
}
void preorderlists(BiTree T, void visit(TElemType))//���������  
{
	if (!T) {
		cout << '.';
		return;
	}
	visit(T->data);
	if (T->lchild != NULL || T->rchild != NULL) {
		cout << '(';
		preorderlists(T->lchild, visit);
		cout << '.';
		preorderlists(T->rchild, visit);
		cout << ')';
	}
}
void preOrder1(BiTree T)     //�ݹ�ǰ����� 
{
	if (T != NULL)
	{
		cout << T->data << " ";
		preOrder1(T->lchild);
		preOrder1(T->rchild);
	}
}
void preOrder2(BiTree root)     //�ǵݹ�ǰ����� 
{
	stack<BiTree> s;
	BiTree p;
	p= root;
	while (p != NULL || !s.empty())
	{
		while (p != NULL)
		{
			cout << p->data << " ";
			s.push(p);
			p = p->lchild;
		}
		if (!s.empty())
		{
			p = s.top();
			s.pop();
			p = p->rchild;
		}
	}
}
void inOrder1(BiTree T)      //�ݹ��������
{
	if (T != NULL)
	{
		inOrder1(T->lchild);
		cout << T->data << " ";
		inOrder1(T->rchild);
	}
}
void inOrder2(BiTree T)      //�ǵݹ��������
{
	stack<BiTree> s;
	BiTree p = T;
	while (p != NULL || !s.empty())
	{
		while (p != NULL)
		{
			s.push(p);
			p = p->lchild;
		}
		if (!s.empty())
		{
			p = s.top();
			cout << p->data << " ";
			s.pop();
			p = p->rchild;
		}
	}
}
void postOrder1(BiTree T)    //�ݹ�������
{
	if (T != NULL)
	{
		postOrder1(T->lchild);
		postOrder1(T->rchild);
		cout << T->data << " ";
	}
}
void postOrder3(BiTree T)     //�ǵݹ�������
{
	stack<BiTree> s;
	BiTree cur;                      //��ǰ��� 
	BiTree pre = NULL;                 //ǰһ�η��ʵĽ�� 
	s.push(T);
	while (!s.empty())
	{
		cur = s.top();
		if ((cur->lchild == NULL&&cur->rchild == NULL) ||
			(pre != NULL && (pre == cur->lchild || pre == cur->rchild)))
		{
			cout << cur->data << " ";  //�����ǰ���û�к��ӽ����ߺ��ӽڵ㶼�ѱ����ʹ� 
			s.pop();
			pre = cur;
		}
		else
		{
			if (cur->rchild != NULL)
				s.push(cur->rchild);
			if (cur->lchild != NULL)
				s.push(cur->lchild);
		}
	}
}
int count(BiTree&T)//ͳ��Ҷ�ӽڵ�
{
	if (!T)return 0;
	if (!T->lchild&&!T->rchild)return 1;
	return count(T->lchild) + count(T->rchild);
}
int main() {
	BiTree T1;
	int k = 4;
	TElemType a[] = { "ABD..EH...CF.I..G.." };
	TElemType s;
	CreateBiTree(T1, a);//����������  
	cout << "������Ϊ:" << endl;
	preorderlists(T1, visit);//��������������
	cout << endl;
	display(T1);
	cout << endl;
	cout <<"Ҷ�ӽڵ���Ϊ��"<< count(T1) << endl;
	cout << "�ݹ�ʵ�������";
	preOrder1(T1);
	cout << endl;
	cout << "�ǵݹ�ǰ�������";
	preOrder2(T1);
	cout << endl;
	cout << "�ݹ��������:";
	inOrder1(T1);
	cout << endl;
	cout << "�ǵݹ��������:";
	inOrder2(T1);
	cout << endl;
	cout << "�ݹ���������";
	postOrder1(T1);
	cout << endl;
	cout << "�ǵݹ�������:";
	postOrder3(T1);
	cout << endl;
	system("pause");
	return 0;
}
