#ifndef TREE_H
#define TREE_H

#include "TreeNode.h"
#include <memory>
#include <vector>

using std::shared_ptr;
using std::vector;
using NodePtr = shared_ptr<TreeNode>;

class Tree
{
private:
	NodePtr root;

public:
	Tree() : root(nullptr) {}
	~Tree() {}

	void Insert(int val);

	void BuildMinTree(const vector<int>& vals);

	void PrintInOrder();
	void PrintPreOrder();
	void PrintPostOrder();

	void PrintByLevel();

	bool IsBalanced();

private:
	NodePtr BuildMinTreeInternal(const vector<int>& vals, int left, int right);

	void PrintInOrderInternal(NodePtr root);
	void PrintPreOrderInternal(NodePtr root);
	void PrintPostOrderInternal(NodePtr root);

	bool IsBalancedInternal(NodePtr root, int* height);
};
#endif