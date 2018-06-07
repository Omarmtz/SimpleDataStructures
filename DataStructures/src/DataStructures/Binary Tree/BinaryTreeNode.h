#pragma once
#include <utility>

template<typename T>
class BinaryTreeNode
{
public:
	BinaryTreeNode(const T& item);
	BinaryTreeNode(T&& item);
	virtual ~BinaryTreeNode();
	
	BinaryTreeNode * left = nullptr;
	BinaryTreeNode * right = nullptr;

	T data;
};

