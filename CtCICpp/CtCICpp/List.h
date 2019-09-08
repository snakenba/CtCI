#ifndef LIST_H
#define LIST_H

#include "ListNode.h"
#include <memory>

using std::shared_ptr;

template<class T>
class List
{
public:
	List() : head(nullptr), tail(nullptr) {}
	~List() {}
	void Insert(T val);
	void Print();

private:
	shared_ptr<ListNode<T>> head;
	shared_ptr<ListNode<T>> tail;
};

#endif
