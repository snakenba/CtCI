#include <iostream>
#include "List.h"
#include "ListNode.h"

using namespace std;

template <class T> 
void List<T>::Insert(T val)
{
	cout << "Insert " << val << endl;
	auto n = make_shared<ListNode<T>>(val);
	if (head == nullptr)
	{
		head = n;
		tail = n;
	}
	else
	{
		tail->next = n;
		tail = n;
	}
}

template <class T>
void List<T>::Print()
{
	cout << "Print: ";
	auto ptr = head;
	while (ptr != nullptr)
	{
		cout << ptr->val;
		ptr = ptr->next;
		if (ptr != nullptr)
		{
			cout << "->";
		}
	}
	cout << endl;
}