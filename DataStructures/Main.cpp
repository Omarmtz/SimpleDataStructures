#include <iostream>
#include <cstdlib>

#include "src/DataStructures/Binary Tree/BinaryTree.h"
#include "src/DataStructures/Binary Tree/BinaryTree.cpp"


void PrintArray(BinaryTree<int> &tree, const std::vector<int> &array);

int main()
{
	//SingleLinkedListExample();

	BinaryTree<int> tree;

	std::cout << "\nInserting\n";
	int random = 0;
	for (size_t i = 0; i < 10; i++)
	{
		random = std::rand() % 30;
		std::cout << random << ",";
		tree.Add(random);
	}

	std::cout << "\n\nPreorder";
	PrintArray(tree, tree.Preorder());
	std::cout << "\nInorder";
	PrintArray(tree, tree.Inorder());
	std::cout << "\nPostorder";
	PrintArray(tree, tree.Postorder());
	
	std::cin.get();
	return 0;
}

void PrintArray(BinaryTree<int> &tree, const std::vector<int>&array)
{
	std::cout << std::endl;
	for (size_t i = 0; i < tree.Size(); i++)
	{
		std::cout << array[i] << ",";
	}
	std::cout << std::endl;
}

