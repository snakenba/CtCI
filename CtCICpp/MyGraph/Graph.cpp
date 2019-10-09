#include "Graph.h"
#include "GraphNode.h"
#include <memory>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

NodePtr Graph::AddNode(int val)
{
	NodePtr n = make_shared<GraphNode>(val);
	nodes.push_back(n);
	return n;
}

void Graph::AddEdge(NodePtr from, NodePtr to)
{
	from->toNodes.push_back(to);
}

bool Graph::CheckReachBFS(NodePtr from, NodePtr to)
{
	if (from == nullptr || to == nullptr)
		return false;

	// Using BFS
	unordered_map<NodePtr, bool> visited;
	queue<NodePtr> q;
	q.push(from);
	while (!q.empty())
	{
		NodePtr n = q.front();
		q.pop();
		if (n == to)
			return true;

		visited[n] = true;

		vector<NodePtr>& toNodes = n->toNodes;
		for (size_t i = 0; i < toNodes.size(); ++i)
		{
			if (visited.find(toNodes[i]) != visited.end())
				continue;

			q.push(toNodes[i]);
		}
	}

	return false;
}

bool Graph::CheckReachDFS(NodePtr from, NodePtr to)
{
	if (from == nullptr || to == nullptr)
		return false;

	unordered_map<NodePtr, bool> visited;
	return CheckReachDFSInternal(from, to, visited);
}

bool Graph::CheckReachDFSInternal(NodePtr n, NodePtr target, unordered_map<NodePtr, bool>& visited)
{
	if (n == target)
		return true;

	visited[n] = true;
	vector<NodePtr>& toNodes = n->toNodes;
	for (int i = 0; i < toNodes.size(); ++i)
	{
		if (visited.find(toNodes[i]) != visited.end())
			continue;

		if (CheckReachDFSInternal(toNodes[i], target, visited))
			return true;
	}

	return false;
}

void Graph::PrintGraph()
{
	vector<NodePtr>::iterator it;
	for (it = this->nodes.begin(); it != this->nodes.end(); ++it)
	{
		NodePtr from = *it;
		vector<NodePtr>& tos = from->toNodes;
		
		cout << from->val << ":";

		for (size_t i = 0; i < tos.size(); ++i)
		{
			cout << tos[i]->val << ",";
		}

		cout << endl;
	}
}