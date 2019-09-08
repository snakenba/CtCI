#ifndef LISTNODE_H
#define LISTNODE_H

#include <memory>
using std::shared_ptr;

template<class T> 
class ListNode
{
public:
	shared_ptr<ListNode> next;
	T val;

	ListNode(T val) : next(nullptr), val(val) {}
};

#endif