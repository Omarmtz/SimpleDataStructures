#include "LinkedList.h"


template<typename T>
LinkedList<T>::LinkedList():
	size(0)
{	
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	Clear();
}

template<typename T>
void LinkedList<T>::Add(T && item)
{
	LinkedListNode<T&>* newNode = new LinkedListNode<T&>(item);
	size++;
	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
}

template<typename T>
void LinkedList<T>::Remove(const T& item)
{
	LinkedListNode<T&>* previousNode = nullptr;
	LinkedListNode<T&>* tmp = head;

	while (tmp != nullptr)
	{
		if (tmp->Get() == item)
		{
			if (tmp == head)
			{
				head = tmp->next;				
			}
			if (tmp == tail)
			{
				tail = previousNode;
			}
			if (previousNode)
			{
				previousNode->next = tmp->next;
			}

			size--;
			delete tmp;
			return;
		}
		previousNode = tmp;
		tmp = tmp->next;
	}
}

template<typename T>
void LinkedList<T>::Clear()
{
	LinkedListNode<T&>* tmp = head;
	size = 0;
	while (head != nullptr)
	{
		tmp = head;
		head = head->next;
		delete tmp;
	}	
}

template<typename T>
bool LinkedList<T>::Contains(const T& item) const
{
	return FindNode(item) != nullptr;
}

template<typename T>
const T & LinkedList<T>::operator[](int index)
{
	LinkedListNode<T&>* tmp = head;
	int counter = 0;
	if (index > size || index < 0)
		throw "Index out of bounds";

	while (tmp != nullptr && counter < index)
	{
		tmp = tmp->next;
		counter++;
	}

	return tmp->Get();
}

template<typename T>
int LinkedList<T>::Size() const
{
	return size;
}

template<typename T>
LinkedListNode<T&>* LinkedList<T>::FindNode(const T & value) const
{	
	LinkedListNode<T&>* tmp = head;

	while (tmp != nullptr)
	{
		if (tmp->Get() == value)
		{
			return tmp;
		}		
		tmp = tmp->next;
	}
	return nullptr;
}

