#ifndef LIST_HPP
#define LIST_HPP
// list.hpp
// Eva Lott, Paul Lancaster
// Created	28/12/17
// Edited	29/12/17
// Contains an abstract linked list class and derived classes for stack and queue data structures.

#include <iostream>

// Abstract List class
template <class T>
class List {
public:
	List (void);
	~List (void);
	virtual void print (void);

	virtual void push (T data);

	// Getters
	virtual long unsigned getLength (void) const {return length;};

protected:
	long unsigned length;
	struct Node {
		T data;
		long unsigned pos;
		Node *next, *previous;
	} *head, *tail;
};

// Constructor, initialise fields
template <class T>
List<T>::List (void)
{
	length = 0;
	head = nullptr;
	tail = nullptr;
}

// Destructor, destroy nodes
template <class T>
List<T>::~List (void)
{
	Node *n = head, *tn;
	while ((tn = n) != nullptr) {
		n = n->next;
		delete tn;
	}
}

// Print list
template <class T>
void List<T>::print (void)
{
	Node *n = head;
	while (n != nullptr) {
		std::cout << n->pos << ":\t" << n->data << "\n";
		n = n->next;
	}
}

// Push the tail
template <class T>
void List<T>::push (T data)
{
	// Create a new node and set it's fields
	Node *newNode = new Node;
	newNode->data = data;
	newNode->pos = length++;
	newNode->previous = tail;
	newNode->next = nullptr;

	// Set the tail to newNode
	if (head == nullptr)
		tail = head = newNode;
	else {
		tail->next = newNode;
		tail = newNode;
	}
}

// Stack derived class
template <class T>
class Stack : public List<T> {
public:
	T pop (void);
};

// Pop the value of the tail then destroy it
template <class T>
T Stack<T>::pop (void)
{
	// Save the value of temp for return later
	T t = List<T>::tail->data;

	// Save the memory location of the old tail
	typename List<T>::Node *tn = List<T>::tail;

	// Set the tail to the previous node and it's next to null
	List<T>::tail = List<T>::tail->previous;
	List<T>::tail->next = nullptr;

	// Delete the old tail
	delete tn;

	--List<T>::length;

	// Return the old data value
	return t;
}

// Queue derived class
template <class T>
class Queue : public List<T> {
public:
	T pop (void);
	void append(Queue<T>);
};

// O(1) time complexity appending of the given queue to the end of this queue
// Does not update the pos because that would be an O(k) operation where k is
// the length of the queue being appended
template <class T>
void Queue<T>::append(Queue<T>* queue){
	queue->head->previous = tail;
	tail->next = queue->head;
	length = length + queue->getLength();
}

// Pop the value of the head then destroy it
template <class T>
T Queue<T>::pop (void)
{
	// Save the value of temp for return later
	T t = List<T>::head->data;

	// Save the memory location of the old head
	typename List<T>::Node *tn = List<T>::head;

	// Set the head to the next node and it's previos to null
	List<T>::head = List<T>::head->next;
	List<T>::head->previous = nullptr;

	// Delete the old tail
	delete tn;

	--List<T>::length;

	// Return the old data value
	return t;
}

#endif // LIST_HPP
