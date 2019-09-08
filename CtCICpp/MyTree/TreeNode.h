#ifndef TREENODE_H
#define TREENODE_H

#include <memory>
using std::shared_ptr;

template <class T>
class TreeNode
{
public:
	T val;
	shared_ptr<TreeNode<T>> left;
	shared_ptr<TreeNode<T>> right;

	TreeNode(T val) : val(val), left(nullptr), right(nullptr) {}
};

#endif