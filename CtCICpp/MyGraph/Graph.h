#ifndef GRAPH_H
#define GRAPH_H

#include "GraphNode.h"
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;
using NodePtr = shared_ptr<GraphNode>;

class Graph
{
private:
	vector<NodePtr> nodes;

public:
	Graph() {}
	~Graph() {}

	NodePtr AddNode(int val);
	void AddEdge(NodePtr from, NodePtr to);
	bool CheckReachBFS(NodePtr from, NodePtr to);
	bool CheckReachDFS(NodePtr from, NodePtr to);

	void PrintGraph();

private:
	bool CheckReachDFSInternal(NodePtr n, NodePtr target, unordered_map<NodePtr, bool>& visited);
};

#endif