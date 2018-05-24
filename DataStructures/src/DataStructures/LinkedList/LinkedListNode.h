#pragma once

template<typename T>
class LinkedListNode
{
public:
	
	LinkedListNode(T&& item);
	virtual ~LinkedListNode();
	
	LinkedListNode * next;

	const T& Get() const;
	void Set(T&& value);

protected:
	T & data;
};

