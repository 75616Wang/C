// 算法设计实验1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;
template<class T>
//交换a,b的值；
void Swap(T&a, T&b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}
template<class T>
class SortList
{
public:
	SortList(int size, T*arr)
	{
		SIZE = size;
		List = new T(SIZE);
		for (int i = 0; i < SIZE; i++)
		{
			List[i] = arr[i];
		}
	}
	void Sort(int left, int right);
	void Sort();
	void Merge(int left, int right, int m);
	void show();

	~SortList() {  }
private:
	T *List;
	int SIZE;
};
template <class T>
void SortList<T>::Sort(int left, int right)
{
	if (right > left) {
		int m = (right + left) / 2;
		Sort(left, m);
		Sort(m + 1, right);
		Merge(left, right, m);
	}
}
template<class T>
void SortList<T>::Sort()
{
	Sort(0, SIZE - 1);
}
template<class T>
void SortList<T>::Merge(int left, int right, int m)
{

	T* temp = new T[right - left + 1];
	int i = left; int j = right; int k = left;
	while ((i <= m) && (j <= right))
	{
		//temp[k++] = List[i] > List[j] ? List[j++] : List[i++];
		if (List[i] > List[j])temp[k++] = List[j++];
		else temp[k++] = List[i++];
	}
	while (i <= m)
	{
		temp[k++] = List[i++];
	}
	while (j <= right)
	{
		temp[k++] = List[j++];
	}
	for (i = 0, k = left; k <= right;)
	{
		List[k++] = temp[i++];
	}
}
template<class T>
void SortList<T>::show()
{
	for (int i = 0; i < SIZE; i++)
		printf("%d\t", List[i]);
	cout << endl;
}

int main()
{

	int arr[10] = { 321,32,213,32,21,4,21,4,5, 13 };
	SortList<int> L(10, arr);
	L.Sort();
	L.show();
	system("pause");
    return 0;
}

