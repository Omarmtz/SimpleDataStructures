#pragma once

template<typename T>
class LinkedListNode
{
public:
	
	LinkedListNode(const T& item);
	LinkedListNode(T&& item);
	virtual ~LinkedListNode();
	
	LinkedListNode * next;
	T data;
};

