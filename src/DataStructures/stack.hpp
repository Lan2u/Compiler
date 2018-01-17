#ifndef STACK_HPP
#define STACK_HPP
// stack.hpp
// Paul Lancaster and Eva Lott
// stack C++ implementation

#include <iostream>

// Stack class
template <class T>
class Stack {
public:
	Stack (void);
	~Stack (void);
	void print (void);
	void push (T);
	T pop (void);

	// Getters
	long long unsigned getLength(void) const { return length; };

private:
	struct Node {
		T data;
		long long unsigned pos;
		Node *next, *previous;
	} *head, *tail;

	long long unsigned length;
};

// Constructor, initialise fields
template <class T>
Stack<T>::Stack (void)
{
	length = 0;
	head = nullptr;
	tail = nullptr;
}

// Destructor, destroy nodes
template <class T>
Stack<T>::~Stack (void)
{
	Node *n = head, *tn;
	while ((tn = n) != nullptr) {
		n = n->next;
		delete tn;
	}
}

// Print list
template <class T>
void Stack<T>::print (void)
{
	Node *n = head;
	while (n != nullptr) {
		std::cout << n->pos << ":\t" << n->data << "\n";
		n = n->next;
	}
}

// Enqueue an element to the queue.
template <class T>
void Stack<T>::push (T data)
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

// Pop the value of the tail then destroy it
template <class T>
T Stack<T>::pop (void)
{
	// Save the value of temp for return later
	T t = tail->data;

	// Save the memory location of the old tail
	Node *tn = tail;

	// Set the tail to the previous node and it's next to null
	tail = tail->previous;
	tail->next = nullptr;

	// Delete the old tail
	delete tn;

	--length;

	// Return the old data value
	return t;
}
#endif // STACK_HPP
