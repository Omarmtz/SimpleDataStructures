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


	std::cout << "Adding 1...12 where x->11,y->12 are lvalues" << std::endl;
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

	int x = 11;
	int y = 12;

	list.Add(x);
	list.Add(y);

	std::cout << std::endl << "Inserting..." << std::endl;
	std::cout << "Insert 400 at index 10 "<< std::endl;
	list.Insert(400, 10);
	std::cout << "Insert 400 at index 12 " << std::endl;
	list.Insert(400, 12);

	
	std::cout << std::endl << "Searching..." << std::endl;
	std::cout << "List contains 5? " << (list.Contains(5) ? "True" : "False") << std::endl;
	std::cout << "List contains 6? " << (list.Contains(6) ? "True" : "False") << std::endl;
	std::cout << "List contains 99? " << (list.Contains(99) ? "True" : "False") << std::endl;
	

	std::cout << std::endl << "Content..." << std::endl;
	for (size_t i = 0; i < list.Size(); i++)
	{
		std::cout << list[i] << ", ";
	}
	std::cout << std::endl;

	std::cout << std::endl << "Removing 1,5,7,99,x->11" << std::endl;
	list.Remove(1);
	list.Remove(5);
	list.Remove(7);
	list.Remove(99);
	list.Remove(x);

	std::cout << std::endl << "After removing..." << std::endl;
	for (size_t i = 0; i < list.Size(); i++)
	{
		std::cout << list[i] << ", ";
	}
	std::cout << std::endl;

	std::cout << std::endl << "List has "<< list.Size() << " elements" << std::endl;
	std::cout << std::endl << "Clearing..." << std::endl;
	list.Clear();
	std::cout << std::endl << "List has " << list.Size() << " elements" << std::endl;
}
