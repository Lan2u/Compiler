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

// Print list in the format with the head element first and tail last:
// $pos1<tab>$data1
// $pos2<tab>$data2
// ...
// Best, Avg, Worst Time Complexity: O(n)
template <class T>
void DoubleLinkedList<T>::print (void)
{
	Node *n = head;
	while (n != nullptr) {
		std::cout << n->pos << ":\t" << n->data << "\n";
		n = n->next;
	}
}

// Add an element to the end of the linked list (Tail position).
// Best, Avg, Worst Time Complexity: O(1)
template <class T>
void DoubleLinkedList<T>::add (T data)
{
	// Create a new node and set it's fields
	Node *newNode = new Node();
	newNode->data = data;
	newNode->pos = length++;
	newNode->previous = tail;
	newNode->next = nullptr;

	
	if (head == nullptr) {
		// Set the tail to newNode since the list is empty
		tail = head = newNode;
	} else {
		// Add the new node and point the tail at the it.
		tail->next = newNode;
		tail = newNode;
	}
}

// Removes the first instance of the given element (head->tail) and maintains existing ordering within the list.
// Best, Avg, Worst Time Complexity: O(1)
template<class T>
void DoubleLinkedList<T>::remove (T element)
{
	Node* node = head;
	while (node != nullptr) {
		if (node->data == element) {
			if (node == head) {
				head = head->next;
				delete node;
				length--;
			}
			else if (node == tail) {
				tail->previous->next = nullptr;
				delete node;
				length--;
			}
			else {
				node->previous->next = node->next;
				node->next->previous = node->previous;
				delete node;
				length--;
			}
			return;
		}
		else {
			node = node->next;
		}
	}
}

// Check if the list contains an element
// Best, Avg, Worst Time Complexity: O(n)
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
