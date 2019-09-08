#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <vector>
#include <memory>
using std::vector;
using std::shared_ptr;

template <class T>
class GraphNode
{
public:
	T val;
	vector<shared_ptr<GraphNode<T>>> toNodes;

	GraphNode(T val) : val(val) {}
};

#endif // !GRAPHNODE_H
