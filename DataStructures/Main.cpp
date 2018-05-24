#include <iostream>

#include "src/DataStructures/LinkedList/LinkedList.h"
#include "src/DataStructures/LinkedList/LinkedList.cpp"

void SingleLinkedListExample();

int main()
{
	SingleLinkedListExample();

	std::cin.get();
	return 0;
}

void SingleLinkedListExample()
{
	LinkedList<int> list;

	list.Add(1);
	list.Add(2);
	list.Add(3);
	list.Add(4);
	list.Add(5);
	list.Add(6);
	list.Add(7);
	list.Add(8);
	list.Add(9);
	list.Add(10);

	list.Remove(1);
	list.Remove(5);
	list.Remove(7);

	std::cout << "Contains 5" << (list.Contains(5) ? " True" : " False") << std::endl;
	std::cout << "Contains 6" << (list.Contains(6) ? " True" : " False") << std::endl;

	std::cout << "Content" << std::endl;
	for (size_t i = 0; i < list.Size(); i++)
	{
		std::cout << list[i] << std::endl;
	}

	list.Clear();
}
