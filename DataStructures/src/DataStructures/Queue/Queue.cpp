#include "Queue.h"

template<typename T>
Queue<T>::Queue():
	DoubleLinkedList()
{
}

template<typename T>
Queue<T>::~Queue()
{
	this->Clear();
}

template<typename T>
const T & Queue<T>::Front()
{
	return this->GetHead();
}

template<typename T>
void Queue<T>::Enqueue(T && item)
{
	Enqueue(std::forward<const T&>(item));
}

template<typename T>
void Queue<T>::Enqueue(const T & item)
{
	this->PushBack(item);
}

template<typename T>
void Queue<T>::Dequeue()
{
	this->PopFront();
}
