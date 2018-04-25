#pragma once
#include "node.h"
template <class type>
class SLL
{
public:
	node<type> *head, *tail;
	unsigned length;
	SLL();
	~SLL();
	bool isEmpty();
	void addHead(node<type> *);
	void addHead(type); // needs copy constructor for type if type
						// is class contains pointer
	void addTail(node<type> *);
	void addTail(type);// needs copy constructor for type if type
					   // is class contains pointer
	node<type> *popHead();
	node<type> *popTail();
	node<type> *findNode(type); //may need to overload operator== for type
	node<type> *popNode(type);
	void deleteHead();
	void deleteTail();
	void deleteNode(type);
	void insertNodeAfter(node<type> *before, node<type> *after);
	void insertNodeAfter(type, type);
	// TODO: implement input, ouput, destroy funcs as non-member with the wanted type
};


// definitions 

template <class type>
SLL<type>::SLL()
{
	head = tail = NULL;
	length = 0;
}

template <class type>
SLL<type>::~SLL()
{

}

template<class type>
bool SLL<type>::isEmpty()
{
	return (head == NULL);
}

template<class type>
void SLL<type>::addHead(node<type>* p)
{
	if (this->isEmpty())
		head = tail = p;
	else
	{
		p->next = head;
		head = p;
	}
}

template<class type>
void SLL<type>::addHead(type info)
{
	node<type> * p = new node<type>(info);
	if (p == NULL)
		return;
	addHead(p);
}

template<class type>
void SLL<type>::addTail(node<type>* p)
{
	if (this->isEmty())
		head = tail = p;
	else
	{
		tail->next = p;
		tail = p;
	}
}

template<class type>
void SLL<type>::addTail(type info)
{
	node<type> * p = new node<type>(info);
	if (p == NULL)
		return;
	addTail(p);
}

template<class type>
node<type>* SLL<type>::popHead()
{
	if (this->isEmpty())
		return NULL;
	node<type> *p = this->head;
	if (this->head == this->tail)
	{
		head = tail = NULL;
		return p;
	}
	head++;
	p->isolate();
	return p;
}

template<class type>
node<type>* SLL<type>::popTail()
{
	if (this->isEmpty())
		return NULL;
	node<type> *p = this->tail;
	if (this->head == this->tail)
	{
		head = tail = NULL;
		return p;
	}
	node<type> *q = this->head;
	while (q->next != this->tail)
		q = q->next;
	q->next = NULL;
	this->tail = q;
	p->isolate();
	return p;
}

template<class type>
node<type>* SLL<type>::findNode(type info)
{
	node<type> *p = this->head;
	while (p)
	{
		if (p->info == info)
			break;
		p = p->next;
	}
	return p;
}

template<class type>
node<type>* SLL<type>::popNode(type info)
{
	node<type> *p = findNode(info);
	if (p == this->head)
		return this->popHead();
	else if (p == this->addTail)
		return this->popTail();
	else
	{
		node<type> q = this->head;
		while (q->next != p)
		{
			q = q->next;
		}
		q->next = p->next;
		p->isolate();
		return p;
	}
}

template<class type>
void SLL<type>::deleteHead()
{
	node<type> *p = this->popHead();
	if (p != NULL)
		delete p;
}

template<class type>
void SLL<type>::deleteTail()
{
	node<type> *p = this->popTail();
	if (p != NULL)
		delete p;
}

template<class type>
void SLL<type>::deleteNode(type info)
{
	node<type> *p = this->popNode(info);
	if (p != NULL)
		delete p;
}

template<class type>
void SLL<type>::insertNodeAfter(node<type>* before, node<type>* after)
{
	if (before == NULL || head == NULL || after == NULL)
		return;
	after->next = before->next;
	before->next = after;
}

template<class type>
void SLL<type>::insertNodeAfter(type beforeInfo, type afterInfo)
{
	node<type> *p = new node<type>(afterInfo);
	insertNodeAfter(this->findNode(beforeInfo), p);
}