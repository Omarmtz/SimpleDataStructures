#pragma once
#include "../DoubleLinkedList/DoubleLinkedList.h"
#include "../DoubleLinkedList/DoubleLinkedList.cpp"

template<typename T>
class Stack : public DoubleLinkedList<T>
{
public:
	Stack();
	virtual ~Stack();

	const T& Peek();

	void Push(T&& item);
	void Push(const T& item);

	void Pop();
};

