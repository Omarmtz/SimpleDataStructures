# Simple data structures in C++
This project is intended to be a practical reference for Simple Data Structures in C++ it is not intended to replace any of the STL or advanced libraries in C++ language.

You can have a quick reference for this data structures in :

[Coursera Data Structures Course](https://www.coursera.org/learn/data-structures)
[Geeks for Geeks Site](https://www.geeksforgeeks.org/data-structures/)

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. 

### Prerequisites

You need to have :
[VisualStudio 2017 (Community Edition)](https://visualstudio.microsoft.com/)

This guide will help you though how to configure Visual Studio for C++ Developing:

[Developing VisualStudio C++ Apps](https://blogs.msdn.microsoft.com/vcblog/2017/04/21/getting-started-with-visual-studio-for-c-and-cpp-development/)

### Installing

Just clone or download this code and run it from Visual Studio (Local Windows Debugger)

### Using data structures in hobby projects

Due restrictions using Templates in C++ always include header files and implementation files when referring to a data structure.

Example:

    #include "src/DataStructures/Binary Tree/BinaryTree.h"
    #include "src/DataStructures/Binary Tree/BinaryTree.cpp"

    int main()
    {
	    BinaryTree<int> tree;
	    tree.Add(1);
	    ...
	}
    

## Running the tests

All the tests are under a project called **Data Structures Test**, using [Google Unit Test Framework](https://github.com/google/googletest)

Tests can be runned from Visual Studio Test Window (Test->Windows->TestExplorer) *(Ctrl + E, T)*

### Test Structure

All the tests are divided in file per DataStructure, for example SimpleLinked List has its own file and Stack has another file for its tests.

Each test try to cover the operations of the data structure.

All tests are written in this form :

 - Using [AAA Unit Test Pattern](https://msdn.microsoft.com/en-us/library/hh694602.aspx)
```
TEST(<DATA_STRUCTURE_NAME>, <ACTION>_<STATEOFTEST>_<RESULT>)
{
 //Arrange
 //Act
 //Assert
}
```
Example:
```
TEST(LinkedListTests, Clear_ListContainsElements_ListCleared) 
{
	//Arrange
	LinkedList<int> list;
	list.Add(1);
	list.Add(2);
	list.Add(3);
	//Act
	list.Clear();
	//Assert	
	EXPECT_EQ(list.Size(), 0);
	EXPECT_ANY_THROW(
	{
		auto a = list[0];
	});
}
```

## Deployment

This application its just for practice and learn its not intended to replace any of the current STL libraries in CPP or to be used in production code.

## Versioning

Use [Git](https://git-scm.com/) for versioning. 

## Authors

* **Omar Martinez** - *Initial work* - [omack47](https://github.com/Omarmtz)

## License

This project is licensed under the MIT License.





