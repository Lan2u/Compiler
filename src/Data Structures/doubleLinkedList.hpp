#ifndef LIST_HPP
#define LIST_HPP
// list.hpp
// Eva Lott, Paul Lancaster
// Created	28/12/17
// Edited	29/12/17
// Contains an abstract linked list class and derived classes for stack and queue data structures.

#include <iostream>

// Doubly LinkedList class
template <class T>
class DoubleLinkedList {
public:
	DoubleLinkedList (void);
	~DoubleLinkedList (void);
	virtual void print (void);
	virtual void push (T data);
	virtual bool contains(T element);

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
DoubleLinkedList<T>::DoubleLinkedList (void)
{
	length = 0;
	head = nullptr;
	tail = nullptr;
}

// Destructor, destroy nodes
template <class T>
DoubleLinkedList<T>::~DoubleLinkedList (void)
{
	Node *n = head, *tn;
	while ((tn = n) != nullptr) {
		n = n->next;
		delete tn;
	}
}

// Print list
template <class T>
void DoubleLinkedList<T>::print (void)
{
	Node *n = head;
	while (n != nullptr) {
		std::cout << n->pos << ":\t" << n->data << "\n";
		n = n->next;
	}
}

// Push the tail
template <class T>
void DoubleLinkedList<T>::push (T data)
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

// Check if the list contains an element
template<class T>
inline bool DoubleLinkedList<T>::contains(T element)
{
	Node* node = head;
	while (node != nullptr) {
		if (node->data == element) {
			return true;
		}
		node = node->next;
	}
	return false;
}

#endif // LIST_HPP
