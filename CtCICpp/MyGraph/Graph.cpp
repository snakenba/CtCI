#include "Graph.h"
#include "GraphNode.h"
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
NodePtr<T> Graph<T>::AddNode(T val)
{
	NodePtr<T> n = make_shared<GraphNode<T>>(val);
	this->nodesMap[n] = vector<NodePtr<T>>();
	return n;
}

template <class T>
void Graph<T>::AddEdge(NodePtr<T> from, NodePtr<T> to)
{
	if (nodesMap.find(from) != nodesMap.end())
	{
		nodesMap[from].push_back(to);
	}
}

template <class T>
void Graph<T>::Print()
{
	for_each(nodesMap.begin(), nodesMap.end(),
		[](pair < NodePtr<T>, vector<NodePtr<T>>> element)
		{
			std::cout << (element.first)->val;
			std::cout << ": ";
			typename std::vector<NodePtr<T>>::iterator it;
			auto vec = element.second;
			for (it = vec.begin(); it != vec.end(); it++)
			{
				std::cout << (*it)->val << ",";
			}

			std::cout << std::endl;
		});
}