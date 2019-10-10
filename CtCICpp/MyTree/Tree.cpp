#include "TreeNode.h"
#include "Tree.h"

#include <iostream>
#include <memory>
#include <vector>
#include <queue>
using namespace std;

void Tree::Insert(int val)
{
	NodePtr n = make_shared<TreeNode>(val);
	if (this->root == nullptr)
	{
		this->root = n;
		return;
	}

	NodePtr curr = this->root;
	while (true)
	{
		if (n->val <= curr->val)
		{
			if (curr->left == nullptr)
			{
				curr->left = n;
				break;
			}
			else
			{
				curr = curr->left;
			}
		}
		else
		{
			if (curr->right == nullptr)
			{
				curr->right = n;
				break;
			}
			else
			{
				curr = curr->right;
			}
		}
	}
}

void Tree::BuildMinTree(const vector<int>& vals)
{
	if (vals.size() == 0)
		return;

	this->root = BuildMinTreeInternal(vals, 0, vals.size() - 1);
}

NodePtr Tree::BuildMinTreeInternal(const vector<int>& vals, int left, int right)
{
	if (left > right)
		return nullptr;

	int mid = left + (right - left) / 2;
	NodePtr n = make_shared<TreeNode>(vals[mid]);
	n->left = BuildMinTreeInternal(vals, left, mid - 1);
	n->right = BuildMinTreeInternal(vals, mid + 1, right);

	return n;
}



void Tree::PrintInOrder()
{
	cout << "In Order:";
	PrintInOrderInternal(this->root);
	cout << endl;
}

void Tree::PrintInOrderInternal(NodePtr root)
{
	if (root == nullptr)
		return;

	PrintInOrderInternal(root->left);
	cout << root->val << ",";
	PrintInOrderInternal(root->right);
}

void Tree::PrintPreOrder()
{
	cout << "Pre Order:";
	PrintPreOrderInternal(this->root);
	cout << endl;
}

void Tree::PrintPreOrderInternal(NodePtr root)
{
	if (root == nullptr)
		return;

	cout << root->val << ",";
	PrintPreOrderInternal(root->left);
	PrintPreOrderInternal(root->right);
}

void Tree::PrintPostOrder()
{
	cout << "Post Order:";
	PrintPostOrderInternal(this->root);
	cout << endl;
}

void Tree::PrintPostOrderInternal(NodePtr root)
{
	if (root == nullptr)
		return;

	PrintPostOrderInternal(root->left);
	PrintPostOrderInternal(root->right);
	cout << root->val << ",";
}

void Tree::PrintByLevel()
{
	vector<vector<int>> levels;
	queue<NodePtr> q;
	q.push(this->root);

	while (!q.empty())
	{
		int nNodes = q.size();
		vector<int> level;
		for (int i = 0; i < nNodes; i++)
		{
			NodePtr np = q.front();
			q.pop();
			level.push_back(np->val);
			if (np->left != nullptr)
				q.push(np->left);

			if (np->right != nullptr)
				q.push(np->right);
		}
		levels.push_back(level);
	}

	for (size_t i = 0; i < levels.size(); ++i)
	{
		cout << "Level " << i << ": ";
		for (size_t j = 0; j < levels[i].size(); ++j)
		{
			cout << levels[i][j] << ",";
		}
		cout << endl;
	}
}

bool Tree::IsBalanced()
{
	int height = 0;
	return IsBalancedInternal(this->root, &height);
}

bool Tree::IsBalancedInternal(NodePtr root, int* height)
{
	if (root == nullptr)
	{
		*height = 0;
		return true;
	}

	int leftHeight = 0;
	if (!IsBalancedInternal(root->left, &leftHeight))
		return false;

	int rightHeight = 0;
	if (!IsBalancedInternal(root->right, &rightHeight))
		return false;

	if (abs(leftHeight - rightHeight) > 1)
		return false;

	*height = max(leftHeight, rightHeight) + 1;
	return true;
}