#ifndef LIST_HPP
#define LIST_HPP
// list.hpp
// Eva Lott
// Created	28/12/17
// Edited	28/12/17
// Contains an abstract linked list class and derived
// classes for stack and queue data structures.

// Abstract List class
template <class Temp>
class List {
public:
	List (void);
	~List (void);
	virtual void push (Temp data);
	virtual long unsigned getLength (void) {return length;};

protected:
	long unsigned length;
	struct Node {
		Temp data;
		long unsigned pos;
		Node *next, *previous;
	};
	Node *head, *tail;
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
	Node *n = head, *tn;
	while ((tn = n) != nullptr) {
		n = n->next;
		delete tn;
	}
}

// Push the tail
template <class Temp> 
void List<Temp>::push (Temp data)
{
	// Create a new node and set it's fields
	Node *newNode = new Node;
	newNode->data = data;
	newNode->pos = ++length;
	newNode->previous = tail;
	newNode->next = nullptr;

	// Set the tail to newNode
	tail = newNode;
}

// Stack derived class
template <class Temp>
class Stack : public List<Temp> {
public:
	Temp pop (void);
};

// Pop the value of the tail then destroy it
template <class Temp>
Temp Stack<Temp>::pop (void)
{
	// Save the value of temp for return later
	Temp t = List<Temp>::tail->data;

	// Save the memory location of the old tail
	typename List<Temp>::Node *tn = List<Temp>::tail;
	
	// Set the tail to the previous node and it's next to null
	List<Temp>::tail = List<Temp>::tail->previous;
	List<Temp>::tail->next = nullptr;

	// Delete the old tail
	delete tn;

	--List<Temp>::length;

	// Return the old data value
	return t;
}

// Queue derived class
template <class Temp>
class Queue : public List<Temp> {
public:
	Temp pop (void);
};

// Pop the value of the head then destroy it
template <class Temp>
Temp Queue<Temp>::pop (void)
{
	// Save the value of temp for return later
	Temp t = List<Temp>::head->data;

	// Save the memory location of the old head
	typename List<Temp>::Node *tn = List<Temp>::head;
	
	// Set the head to the next node and it's previos to null
	List<Temp>::head = List<Temp>::head->next;
	List<Temp>::head->previous = nullptr;

	// Delete the old tail
	delete tn;

	--List<Temp>::length;

	// Return the old data value
	return t;
}

#endif // LIST_HPP
