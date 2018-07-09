#pragma once
#include "DoubleLinkedListNode.h"
#include "DoubleLinkedListNode.cpp"

template<typename T>
class DoubleLinkedList
{
public:
	DoubleLinkedList();
	virtual ~DoubleLinkedList();

	void PushBack(T&& item);
	void PushBack(const T& item);

	void PushFront(T&& item);
	void PushFront(const T& item);

	void PopFront();
	const T& GetHead();
	void PopBack();
	const T& GetTail();

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
