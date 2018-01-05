#ifndef LIST_HPP
#define LIST_HPP
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
	virtual void print (void);
	virtual void add (T data);
	virtual void remove(T element);
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
inline void DoubleLinkedList<T>::remove(T element)
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
	// TODO. Throw an exception to indicate that the element wasn't found.
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
