#ifndef TREE_H
#define TREE_H

#include <memory>
#include "TreeNode.h"

using std::shared_ptr;

template <class T>
class Tree
{
public:
	Tree() : m_root(nullptr) {}
	~Tree() {}

	void Insert(T val);

	void PrintInOrder();
	void PrintPreOrder();
	void PrintPostOrder();

private:
	shared_ptr<TreeNode<T>> m_root;
};

#endif