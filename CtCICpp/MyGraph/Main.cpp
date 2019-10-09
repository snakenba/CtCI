// MyGraph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Graph.h"
#include "GraphNode.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

	Graph g;
	NodePtr n1 = g.AddNode(1);
	NodePtr n2 = g.AddNode(2);
	NodePtr n3 = g.AddNode(3);
	NodePtr n4 = g.AddNode(4);
	NodePtr n5 = g.AddNode(5);

	g.AddEdge(n1, n2);
	g.AddEdge(n2, n3);
	g.AddEdge(n4, n2);
	g.AddEdge(n3, n4);

	g.PrintGraph();

	cout << "3 to 2 " << g.CheckReachBFS(n3, n2) << endl;
	cout << "5 to 2 " << g.CheckReachBFS(n5, n2) << endl;
	cout << "2 to 1 " << g.CheckReachBFS(n2, n1) << endl;

	cout << "3 to 2 " << g.CheckReachDFS(n3, n2) << endl;
	cout << "5 to 2 " << g.CheckReachDFS(n5, n2) << endl;
	cout << "2 to 1 " << g.CheckReachDFS(n2, n1) << endl;

	return 0;
}
