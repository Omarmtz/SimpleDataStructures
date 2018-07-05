#include "BinaryTreeNode.h"
#include <utility>

template<typename T>
BinaryTreeNode<T>::BinaryTreeNode(const T & item)
{
	this->data = item;
}

template<typename T>
BinaryTreeNode<T>::BinaryTreeNode(T&& item)
	: data(std::forward<T>(item))
{

}

template<typename T>
BinaryTreeNode<T>::~BinaryTreeNode()
{
}
