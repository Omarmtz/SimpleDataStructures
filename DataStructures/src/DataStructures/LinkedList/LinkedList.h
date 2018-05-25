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

	void Insert(T&& item,const int index);
	void Insert(const T& item,const int index);

	
	void Remove(const T& item);
	void Clear();
	bool Contains(const T& item) const;

	const T& operator[](int index);
	
	int Size() const;

private:
	
	LinkedListNode<T>* FindNode(const T& value) const;
	LinkedListNode<T>* GetNodeInIndex(const int index)const;
	
	int size;

	LinkedListNode<T>* head;
	LinkedListNode<T>* tail;
};


