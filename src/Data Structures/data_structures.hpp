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

// Stack derived class
template <class T>
class Stack : public DoubleLinkedList<T> {
public:
	T pop (void);
};

// Pop the value of the tail then destroy it
template <class T>
T Stack<T>::pop (void)
{
	// Save the value of temp for return later
	T t = DoubleLinkedList<T>::tail->data;

	// Save the memory location of the old tail
	typename DoubleLinkedList<T>::Node *tn = DoubleLinkedList<T>::tail;

	// Set the tail to the previous node and it's next to null
	DoubleLinkedList<T>::tail = DoubleLinkedList<T>::tail->previous;
	DoubleLinkedList<T>::tail->next = nullptr;

	// Delete the old tail
	delete tn;

	--DoubleLinkedList<T>::length;

	// Return the old data value
	return t;
}

// Queue derived class
template <class T>
class Queue : public DoubleLinkedList<T> {
public:
	T pop (void);
	void append(Queue<T>*);
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
	T t = DoubleLinkedList<T>::head->data;

	// Save the memory location of the old head
	typename DoubleLinkedList<T>::Node *tn = DoubleLinkedList<T>::head;

	// Set the head to the next node and it's previos to null
	DoubleLinkedList<T>::head = DoubleLinkedList<T>::head->next;
	DoubleLinkedList<T>::head->previous = nullptr;

	// Delete the old tail
	delete tn;

	--DoubleLinkedList<T>::length;

	// Return the old data value
	return t;
}

#endif // LIST_HPP
