#include "DoubleLinkedList.h"

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList():
	size(0)
{
}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
	Clear();
}

template<typename T>
void DoubleLinkedList<T>::Add(T && item)
{
	Add(std::forward<const T&>(item));
}

template<typename T>
void DoubleLinkedList<T>::Add(const T & item)
{
	DoubleLinkedListNode<T>* newNode = new DoubleLinkedListNode<T>(item);
	size++;
	if (head == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode->previous = tail;
		tail->next = newNode;
		tail = newNode;
	}
}


template<typename T>
void DoubleLinkedList<T>::Remove(T && item)
{
	this->Remove(std::forward<const T&>(item));
}

template<typename T>
void DoubleLinkedList<T>::Remove(const T & item)
{	
	DoubleLinkedListNode<T>* tmp = head;
	
	while (tmp != nullptr)
	{
		if (tmp->data == item)
		{
			if (tmp == head)
			{
				head = tmp->next;

				if (head != nullptr)
				{
					head->previous = nullptr;
				}			
			}
			if (tmp == tail)
			{					
				tail = tmp->previous;
				
				if (tail != nullptr)
				{
					tail->next = nullptr;
				}
			}
			if (tmp->next != nullptr && tmp->previous != nullptr)
			{
				tmp->previous->next = tmp->next;
				tmp->next->previous = tmp->previous;
			}

			size--;
			delete tmp;
			return;
		}
		tmp = tmp->next;
	}
}

template<typename T>
bool DoubleLinkedList<T>::Contains(T && item) const
{
	return this->Contains(std::forward<const T&>(item));
}

template<typename T>
bool DoubleLinkedList<T>::Contains(const T & item) const
{
	return FindNode(item) != nullptr;
}

template<typename T>
void DoubleLinkedList<T>::Clear()
{
	DoubleLinkedListNode<T>* tmp = head;	
		
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
const T & DoubleLinkedList<T>::operator[](int index)
{
	DoubleLinkedListNode<T>* tmp = head;
	int counter = 0;
	if (index > size || index < 0)
		throw "Index out of bounds";
	if (size == 0)
		throw "No element in list";


	while (tmp != nullptr && counter < index)
	{
		tmp = tmp->next;
		counter++;
	}

	return tmp->data;
}

template<typename T>
int DoubleLinkedList<T>::Size() const
{
	return size;
}

template<typename T>
DoubleLinkedListNode<T>* DoubleLinkedList<T>::FindNode(const T & value) const
{
	DoubleLinkedListNode<T>* tmp = head;

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
