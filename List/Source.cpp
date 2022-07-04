#include"List.h"


int main()
{
	List<int> lst;

	int numbersCount = 0;
	cin >> numbersCount;

	for (int i = 0; i < numbersCount; i++)
	{
		lst.PushBack(rand() % 10);
	}
	lst.PushFront(100);
	lst.Insert(1000, 3);
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << "\n";
	}

	cout << lst.GetSize() << endl;

	lst.Clear();
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << "\n";
	}
	cout << lst.GetSize();
}
