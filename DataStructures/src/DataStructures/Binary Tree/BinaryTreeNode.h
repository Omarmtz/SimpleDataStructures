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

	BinaryTreeNode * parent = nullptr;

	T data;
};

