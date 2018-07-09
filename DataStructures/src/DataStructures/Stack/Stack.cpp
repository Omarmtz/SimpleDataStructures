#include "Stack.h"

template<typename T>
Stack<T>::Stack():
	DoubleLinkedList<T>()
{

}

template<typename T>
Stack<T>::~Stack()
{
	this->Clear();
}

template<typename T>
const T & Stack<T>::Peek()
{
	return this->GetTail();
}

template<typename T>
void Stack<T>::Push(T && item)
{
	Push(std::forward<const T&>(item));
}

template<typename T>
void Stack<T>::Push(const T & item)
{
	this->PushBack(item);
}

template<typename T>
void Stack<T>::Pop()
{
	this->PopBack();
}


