#pragma once
template<class T>
//½»»»a,bµÄÖµ£»
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
	SortList(int size,T*arr)
	{
		SIZE = size;
		List = new T(SIZE);
		List = arr;
	}
	void Sort(int left, int right);
	void Merge(int a, int b, int m);
	void show();
	~SortList() { delete[]List; }
private:
	T *List;
	int SIZE;
};
template <class T>
void SortList<T>::Sort(int left, int right)
{
	if (right - left == 0)
		return;
	if (right-left==1)
	{
		if (List[right] < List[left])
			Swap(List[left], List[right]);
	}
	int m = (right + left) / 2;
	Sort(left, m);
	Sort(m + 1, right);
	Merge(left, right, m);
}
template<class T>
void SortList<T>::Merge(int a, int b, int m)
{
	T *temp = new T(b - a);
	int i = 0; int j = 0; int k = 0;
	for (; i < b - m && i < m - a; i++)
	{
		if (List[a + j] < List[m + k])
		{
			temp[i] = List[a + j];
				j++;
		}
		else
		{
			temp[i] = List[m + k];
			k++;
		}
	}
	for (int i = 0; i < b-a; i++)
	{
		List[a + i] = temp[i];
	}
	show();
}
template<class T>
void SortList<T>::show()
{
	for (int i = 0; i < SIZE; i++)
		cout << List[i] << "\t";
	cout << endl;
}