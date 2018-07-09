#pragma once
#include "DoubleLinkedListNode.h"
#include "DoubleLinkedListNode.cpp"

template<typename T>
class DoubleLinkedList
{
public:
	DoubleLinkedList();
	virtual ~DoubleLinkedList();

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
	int size;
	
	DoubleLinkedListNode<T>* FindNode(const T& value) const;

	DoubleLinkedListNode<T>* head = nullptr;
	DoubleLinkedListNode<T>* tail = nullptr;
};
