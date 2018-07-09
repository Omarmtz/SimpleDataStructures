#pragma once
template<typename T>
class DoubleLinkedListNode
{
public:
	
	DoubleLinkedListNode(const T& item);
	DoubleLinkedListNode(T&& item);
	virtual ~DoubleLinkedListNode();

	DoubleLinkedListNode * next = nullptr;
	DoubleLinkedListNode * previous = nullptr;
	T data;
};


