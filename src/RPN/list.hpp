#ifndef LIST_HPP
#define LIST_HPP
// list.hpp
// Eva Lott
// Contains an abstract linked list class and derived
// classes for stack and queue data structures.

#include <iostream>

// Abstract List class
template <class Temp>
class List {
protected:
	List (void);
	~List (void);
	virtual long unsigned getLength (void);

private:
	struct Node {
		Temp data;
		long unsigned pos;
		Node *next, *previous;
	} *head, *tail;

	long unsigned length;
};

// Constructor, initialise fields
template <class Temp>
List<Temp>::List (void)
{
	length = 0;
	head = tail = nullptr;
}

// Destructor, destroy nodes
template <class Temp> 
List<Temp>::~List (void)
{
	Temp *n = head, *tn;
	while ((tn = n) != nullptr) {
		n = n->next;
		delete tn;
	}
}

// Getters
template <class Temp> 
long unsigned List<Temp>::getLength (void) {return length;}


// Stack derived class
template <class Temp>
class Stack : public List<Temp> {
public:
	bool push (Temp);
	Temp pop (void);
};

// Push the tail
template <class Temp> 
bool Stack<Temp>::push (Temp)
{
	Node *n = List<Temp>::tail, *tn;
}


#endif // LIST_HPP
