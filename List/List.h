#include <iostream>
using namespace std;
#pragma once

template < typename T>
class List
{
public:
	List();
	~List();

	void PushBack(T data);
	void PushFront(T data);
	void Clear();
	void DeleteFromFront();
	void DeleteFromBack();
	void DeleteByIndex(unsigned int index);
	void Insert(T data, unsigned int index);
	T& operator [](const int index);
	int GetSize() const;
private:

	template < typename T>
	class Node
	{
	public:
		T data;
		Node* pNext = nullptr;
		Node* pPrev = nullptr;
		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	Node<T>* head;
	Node<T>* tail;
	int Size;
};

template < typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
	tail = nullptr;
}

template < typename T>
int List<T>::GetSize() const
{
	return Size;
}

template < typename T>
List<T>::~List()
{
	Clear();
}

template<typename T>
void List<T>::PushBack(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
		tail = head;
	}
	else
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
		current->pPrev = current;
	}

	Size++;
}

template<typename T>
void List<T>::PushFront(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::Clear()
{
	while (Size)
	{
		DeleteFromFront();
	}
}

template<typename T>
void List<T>::DeleteFromFront()
{
	Node<T>* temp = head;

	head = head->pNext;
	delete[] temp;

	Size--;
}

template<typename T>
void List<T>::DeleteFromBack()
{
	DeleteByIndex(Size - 1);
}

template<typename T>
void List<T>::DeleteByIndex(unsigned int index)
{
	if (index == 0 || index < 0)
	{
		DeleteFromFront();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		//FindAddressByIndex(index);

		Node<T>* DeleteNode = previous->pNext;

		previous->pNext = DeleteNode->pNext;

		delete[] DeleteNode;
		Size--;
	}
}

template<typename T>
void List<T>::Insert(T data, unsigned int index)
{
	if (index == 0 || index < 0)
	{
		PushFront(data);
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		//FindAddressByIndex(index);

		//Node<T>* newNode = new Node<T>(data, previous->pNext);
		//previous->pNext = newNode;

		previous->pNext = new Node<T>(data, previous->pNext);

		Size++;
	}
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;

	Node<T>* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}


