#ifndef GRAPH_H
#define GRAPH_H

#include "GraphNode.h"
#include <vector>
#include <memory>
#include <unordered_map>

using std::vector;
using std::shared_ptr;
using std::unordered_map;

template <typename T>
using NodePtr = shared_ptr<GraphNode<T>>;

template <class T>
class Graph
{
private:
	unordered_map<NodePtr<T>, vector<NodePtr<T>>> nodesMap;

public:
	Graph() {}
	~Graph() {}
	NodePtr<T> AddNode(T val);
	void AddEdge(NodePtr<T> from, NodePtr<T> to);
	void Print();
};

#endif // !GRAPH_H
