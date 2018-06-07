#include "BinaryTree.h"

#include <iostream>

template<typename T>
inline BinaryTree<T>::BinaryTree()
	:size(0)
{

}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
	Clear();
}

template<typename T>
void BinaryTree<T>::Add(T && item)
{
	Add(std::forward<const T&>(item));
}

template<typename T>
void BinaryTree<T>::Add(const T & item)
{
	if (this->root == nullptr)
	{
		root = new BinaryTreeNode<T>(item);
		size++;
		return;
	}

	Add(this->root, item);
}

template<typename T>
void BinaryTree<T>::Clear()
{
	Clear(root);
	size = 0;
	this->root = nullptr;
}

template<typename T>
std::vector<T> BinaryTree<T>::Preorder()
{
	std::vector<T> array;
	Preorder(root, array);	
	return array;
}

template<typename T>
std::vector<T> BinaryTree<T>::Inorder()
{
	std::vector<T> array;
	Inorder(root, array);
	return array;
}

template<typename T>
std::vector<T> BinaryTree<T>::Postorder()
{
	std::vector<T> array;
	Postorder(root, array);
	return array;
}

template<typename T>
int BinaryTree<T>::Size()
{
	return size;
}

template<typename T>
void BinaryTree<T>::Add(BinaryTreeNode<T>* node, const T & item)
{
	if (node == nullptr)
	{
		return;
	}

	if (node->data > item)
	{
		Add(node->left, item);
	}
	else
	{
		Add(node->right, item);
	}

	if (node->data > item && node->left == nullptr)
	{
		BinaryTreeNode<T>* newNode = new BinaryTreeNode<T>(item);
		node->left = newNode;
		size++;
	}
	else if (node->data <= item && node->right == nullptr)
	{
		BinaryTreeNode<T>* newNode = new BinaryTreeNode<T>(item);
		node->right = newNode;
		size++;
	}
}

template<typename T>
void BinaryTree<T>::Clear(BinaryTreeNode<T>* node)
{
	if (node == nullptr)
	{
		return;
	}

	Clear(node->left);
	Clear(node->right);
	delete node;	
}

template<typename T>
void BinaryTree<T>::Preorder(BinaryTreeNode<T>* node, std::vector<T>& array)
{
	if (node == nullptr)
	{
		return;
	}

	array.push_back(node->data);
	Preorder(node->left, array);
	Preorder(node->right, array);
}

template<typename T>
void BinaryTree<T>::Inorder(BinaryTreeNode<T>* node, std::vector<T>& array)
{
	if (node == nullptr)
	{
		return;
	}
		
	Preorder(node->left, array);	
	array.push_back(node->data);
	Preorder(node->right, array);
}

template<typename T>
void BinaryTree<T>::Postorder(BinaryTreeNode<T>* node, std::vector<T>& array)
{
	if (node == nullptr)
	{
		return;
	}

	Preorder(node->left, array);	
	Preorder(node->right, array);
	array.push_back(node->data);
}
