// CtCICpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "List.h"
#include "List.cpp"

int main()
{
    std::cout << "Hello World!\n";
	List<int> iList;
	iList.Insert(2);
	iList.Insert(3);
	iList.Insert(4);
	iList.Print();

	return 0;
}