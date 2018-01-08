#ifndef DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_HPP
// Eva Lott, Paul Lancaster
// Created	28/12/17
// Contains an DoublyLinkedList

#include <iostream>

// Doubly LinkedList class
template <class T>
class DoubleLinkedList {
public:
	DoubleLinkedList (void);
	~DoubleLinkedList (void);
	void print (void);
	void add (T);
	void remove (T);
	bool contains (T);

	// Getters
	long long unsigned getLength(void) const { return length; };

protected:
	struct Node {
		T data;
		long long unsigned pos;
		Node *next, *previous;
	} *head, *tail;

	long long unsigned length;
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
void DoubleLinkedList<T>::add (T data)
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

template<class T>
void DoubleLinkedList<T>::remove (T element)
{
	Node* node = head;
	while (node != nullptr) {
		if (node->data == element) {
			if (node == head) {
				delete node;
				head = nullptr;
				tail = nullptr;
				length = 0;
			}
			if (node == tail) {
				node->previous->next = nullptr;
				delete node;
				length--;
			}

			node->previous->next = node->next;
			node->next->previous = node->previous;
			delete node;
			length--;
		}
		else {
			node = node->next;
		}
	}
}

// Check if the list contains an element
template<class T>
bool DoubleLinkedList<T>::contains (T element)
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

#endif // DOUBLELINKEDLIST_HPP
