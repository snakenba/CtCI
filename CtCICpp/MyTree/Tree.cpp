#include "Tree.h"
#include "TreeNode.h"

#include <iostream>
using namespace std;

template <class T>
void Tree<T>::Insert(T val)
{
	shared_ptr<TreeNode<T>> n = make_shared<TreeNode<T>>(val);
	if (this->m_root == nullptr)
	{
		this->m_root = n;
		return;
	}

	auto ptr = m_root;
	while (true)
	{
		if (val <= ptr->val)
		{
			if (ptr->left == nullptr)
			{
				ptr->left = n;
				break;
			}
			
			ptr = ptr->left;
		}
		else
		{
			if (ptr->right == nullptr)
			{
				ptr->right = n;
				break;
			}

			ptr = ptr->right;
		}
	}
}

template <class T>
void Tree<T>::PrintPreOrder()
{
	cout << "PreOrder: " << endl;
	PreOrderHelper(this->m_root);
	cout << endl;
}

template <class T>
void PreOrderHelper(shared_ptr<TreeNode<T>> root)
{
	if (root == nullptr) return;

	cout << root->val << ",";
	PreOrderHelper(root->left);
	PreOrderHelper(root->right);
}

template <class T>
void Tree<T>::PrintInOrder()
{
	cout << "InOrder: " << endl;
	InOrderHelper(this->m_root);
	cout << endl;
}

template <class T>
void InOrderHelper(shared_ptr<TreeNode<T>> root)
{
	if (root == nullptr) return;

	InOrderHelper(root->left);
	cout << root->val << ",";
	InOrderHelper(root->right);
}

template <class T>
void Tree<T>::PrintPostOrder()
{
	cout << "PostOrder: " << endl;
	PostOrderHelper(this->m_root);
	cout << endl;
}

template <class T>
void PostOrderHelper(shared_ptr<TreeNode<T>> root)
{
	if (root == nullptr) return;

	PostOrderHelper(root->left);
	PostOrderHelper(root->right);
	cout << root->val << ",";
}