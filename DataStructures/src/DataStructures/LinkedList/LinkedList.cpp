#include "LinkedList.h"
#include <utility>

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
void LinkedList<T>::Insert(T && item, const int index)
{	
	this->Insert(std::forward<const T&>(item), index);
}

template<typename T>
void LinkedList<T>::Insert(const T & item, const int index)
{
	LinkedListNode<T>* newNode = new LinkedListNode<T>(item);
	LinkedListNode<T>* targetNode = GetNodeInIndex(index);

	newNode->next = targetNode->next;
	targetNode->next = newNode;

	size++;
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
	return GetNodeInIndex(index)->data;
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

template<typename T>
LinkedListNode<T>* LinkedList<T>::GetNodeInIndex(const int index) const
{
	LinkedListNode<T>* tmp = head;
	int counter = 0;
	if (index >= size || index < 0)
		throw "Index out of bounds";

	while (tmp != nullptr && counter < index)
	{
		tmp = tmp->next;
		counter++;
	}

	return tmp;
}

