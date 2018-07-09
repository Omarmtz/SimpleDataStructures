#pragma once
#include "../DoubleLinkedList/DoubleLinkedList.h"
#include "../DoubleLinkedList/DoubleLinkedList.cpp"

template<typename T>
class Queue : public DoubleLinkedList<T>
{
public:
	Queue();
	virtual ~Queue();

	const T& Front();
	
	void Enqueue(T&& item);
	void Enqueue(const T& item);
	
	void Dequeue();
};

