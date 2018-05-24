#include "LinkedListNode.h"

template<typename T>
LinkedListNode<T>::LinkedListNode(T&& item)
	: data(item)
{
	
}

template<typename T>
LinkedListNode<T>::~LinkedListNode()
{
}

template<typename T>
const T & LinkedListNode<T>::Get() const
{
	return data;
}

template<typename T>
void LinkedListNode<T>::Set(T && value)
{
	data = value;
}
