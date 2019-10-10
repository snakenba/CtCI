#ifndef TREENODE_H
#define TREENODE_H

#include <memory>

using std::shared_ptr;

class TreeNode
{
public:
	shared_ptr<TreeNode> left;
	shared_ptr<TreeNode> right;
	int val;

	TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
	~TreeNode() {}
};

#endif