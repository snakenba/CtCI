// MyGraph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Graph.h"
#include "Graph.cpp"
#include "GraphNode.h"

int main()
{
    std::cout << "Hello World!\n";

	Graph<int> g;
	NodePtr<int> n1 = g.AddNode(1);
	NodePtr<int> n2 = g.AddNode(2);
	NodePtr<int> n3 = g.AddNode(3);

	g.AddEdge(n1, n2);
	g.AddEdge(n2, n3);

	g.Print();
	return 0;
}
