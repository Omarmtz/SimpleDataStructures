#include "DoubleLinkedListNode.h"
#include <utility>

template<typename T>
DoubleLinkedListNode<T>::DoubleLinkedListNode(const T & item)
{
	this->data = item;
}

template<typename T>
DoubleLinkedListNode<T>::DoubleLinkedListNode(T && item)
	: data(std::forward<T>(item))
{
}

template<typename T>
DoubleLinkedListNode<T>::~DoubleLinkedListNode()
{

}