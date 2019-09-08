// MyTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Tree.h"
#include "Tree.cpp"

int main()
{
    std::cout << "Hello World!\n";
	Tree<int> iTree;
	iTree.Insert(3);
	iTree.Insert(1);
	iTree.Insert(4);
	iTree.Insert(5);
	iTree.Insert(2);

	iTree.PrintPreOrder();
	iTree.PrintInOrder();
	iTree.PrintPostOrder();
}