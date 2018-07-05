#pragma once

#include "LinkedListNode.h"
#include "LinkedListNode.cpp"

template<typename T>
class LinkedList
{
public:
	LinkedList();
	virtual ~LinkedList();

	void Add(T&& item);
	void Add(const T& item);
	
	void Remove(T&& item);
	void Remove(const T& item);

	bool Contains(T&& item) const;
	bool Contains(const T& item) const;

	void Clear();	

	const T& operator[](int index);

	int Size() const;

private:
	
	LinkedListNode<T>* FindNode(const T& value) const;
	
	int size;

	LinkedListNode<T>* head = nullptr;
	LinkedListNode<T>* tail = nullptr;
};


