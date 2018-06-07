#pragma once
#include "BinaryTreeNode.h"
#include "BinaryTreeNode.cpp"

#include <vector>

template<typename T>
class BinaryTree
{
public:
	BinaryTree();
	virtual ~BinaryTree();

	void Add(T&& item);
	void Add(const T & item);

	void Delete(T item);
	void Find(T item);
	void Clear();

	std::vector<T> Preorder();
	std::vector<T> Inorder();
	std::vector<T> Postorder();

	int Size();
	
private:
	int size;

	void Add(BinaryTreeNode<T>* node, const T & item);

	void Clear(BinaryTreeNode<T>* node);

	void Preorder(BinaryTreeNode<T>* node, std::vector<T>& array);
	void Inorder(BinaryTreeNode<T>* node, std::vector<T>& array);
	void Postorder(BinaryTreeNode<T>* node, std::vector<T>& array);

	BinaryTreeNode<T>* root;
};

