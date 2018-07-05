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
	bool Contains(const T& item);
	void Clear();

	const std::vector<T>Preorder();
	const std::vector<T>Inorder();
	const std::vector<T>Postorder();

	int Size();

private:
	int size;

	void Add(BinaryTreeNode<T>* node, const T & item);

	void Clear(BinaryTreeNode<T>* node);

	void Delete(BinaryTreeNode<T>* node, const T & item);

	void Preorder(BinaryTreeNode<T>* node, std::vector<T>& array);
	void Inorder(BinaryTreeNode<T>* node, std::vector<T>& array);
	void Postorder(BinaryTreeNode<T>* node, std::vector<T>& array);

	BinaryTreeNode<T>* FindNode(BinaryTreeNode<T>* node,const T& item);
	BinaryTreeNode<T>* FindNextNode(BinaryTreeNode<T>* node, const T& item);
	
	void FirstDeletionCase(BinaryTreeNode<T> * node);	
	void SecondDeletionCaseLeft(BinaryTreeNode<T> * node);	
	void SecondDeletionCaseRight(BinaryTreeNode<T> * node);
	void ThirdDeletionCase(BinaryTreeNode<T> * node);

	BinaryTreeNode<T>* root;
};

