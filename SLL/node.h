#pragma once
#include <iostream>
template <class type>
class node
{
public:
	type info;
	node *next;
	node();
	node(type);
	~node();
	void isolate();
};


// definitions
template <class type>
void swap(node<type> *a, node<type> *b)
{
	if (a == b)
		return;
	swap(a->info, b->info);
}

template<class type>
node<type>::node()
{
	this->next = NULL;
}

template<class type>
node<type>::node(type info)
{
	this->info = info;
	this->next = NULL;
}

template<class type>
node<type>::~node()
{
}

template<class type>
void node<type>::isolate()
{
	this->next = NULL;
}

