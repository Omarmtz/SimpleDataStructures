#include "LinkedList.h"
#include <utility>

template<typename T>
LinkedList<T>::LinkedList() :
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
	Add(std::forward<const T&>(item));
}

template<typename T>
void LinkedList<T>::Add(const T & item)
{
	LinkedListNode<T>* newNode = new LinkedListNode<T>(item);
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
void LinkedList<T>::Remove(T && item)
{
	this->Remove(std::forward<const T&>(item));
}

template<typename T>
void LinkedList<T>::Remove(const T& item)
{
	LinkedListNode<T>* previousNode = nullptr;
	LinkedListNode<T>* tmp = head;

	while (tmp != nullptr)
	{
		if (tmp->data == item)
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
	LinkedListNode<T>* tmp = head;

	while (head != nullptr)
	{
		tmp = head;
		head = head->next;
		delete tmp;
	}

	head = nullptr;
	tail = nullptr;
	size = 0;
}

template<typename T>
bool LinkedList<T>::Contains(T && item) const
{
	return this->Contains(std::forward<const T&>(item));
}

template<typename T>
bool LinkedList<T>::Contains(const T& item) const
{
	return FindNode(item) != nullptr;
}

template<typename T>
const T & LinkedList<T>::operator[](int index)
{
	LinkedListNode<T>* tmp = head;
	int counter = 0;
	if (index > size || index < 0)
	{
		throw "Index out of bounds";
	}		
	if (size == 0)
	{
		throw "No element in list";
	}

	while (tmp != nullptr && counter < index)
	{
		tmp = tmp->next;
		counter++;
	}

	return tmp->data;
}

template<typename T>
int LinkedList<T>::Size() const
{
	return size;
}

template<typename T>
LinkedListNode<T>* LinkedList<T>::FindNode(const T & value) const
{
	LinkedListNode<T>* tmp = head;

	while (tmp != nullptr)
	{
		if (tmp->data == value)
		{
			return tmp;
		}
		tmp = tmp->next;
	}
	return nullptr;
}

