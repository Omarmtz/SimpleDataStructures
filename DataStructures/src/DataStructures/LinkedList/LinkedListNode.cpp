#include "LinkedListNode.h"
#include <utility>

template<typename T>
LinkedListNode<T>::LinkedListNode(const T & item)
{
	this->data = item;
}

template<typename T>
LinkedListNode<T>::LinkedListNode(T&& item)
	: data(std::forward<T>(item))
{
	
}

template<typename T>
LinkedListNode<T>::~LinkedListNode()
{
}
