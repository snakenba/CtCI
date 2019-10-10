// MyTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";
	Tree tree;
	tree.BuildMinTree(vector<int>({ 1, 2, 3, 4, 5, 6, 7, 8 }));

	tree.PrintPreOrder();
	tree.PrintInOrder();
	tree.PrintPostOrder();

	tree.PrintByLevel();

	cout << "Tree balanced? " << tree.IsBalanced() << endl;

	Tree tree2;
	tree2.Insert(3);
	tree2.Insert(1);
	tree2.Insert(2);

	cout << "Tree 2 balanced? " << tree2.IsBalanced() << endl;
}