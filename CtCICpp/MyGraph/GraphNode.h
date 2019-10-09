#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <memory>
#include <vector>

using std::shared_ptr;
using std::vector;

class GraphNode
{
public:
	vector<shared_ptr<GraphNode>> toNodes;
	int val;

	GraphNode(int val) : val(val) {}
	~GraphNode() {}
};

#endif