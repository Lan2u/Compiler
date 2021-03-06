#ifndef QUEUE_HPP
#define QUEUE_HPP
// queue.hpp
// Paul Lancaster and Eva Lott
// queue C++ implementation

#include <iostream>

// Queue class
template <class T>
class Queue {
public:
	Queue (void);
	~Queue (void);
	void print (void);
	void enqueue (T);
	T dequeue (void);
	void append (Queue<T>*);

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
Queue<T>::Queue (void)
{
	length = 0;
	head = nullptr;
	tail = nullptr;
}

// Destructor, destroy nodes
template <class T>
Queue<T>::~Queue (void)
{
	Node *n = head, *tn;
	while ((tn = n) != nullptr) {
		n = n->next;
		delete tn;
	}
}

// Print list
template <class T>
void Queue<T>::print (void)
{
	Node *n = head;
	while (n != nullptr) {
		std::cout << n->pos << ":\t" << n->data << "\n";
		n = n->next;
	}
}

// Enqueue an element to the queue.
template <class T>
void Queue<T>::enqueue (T data)
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

// Pop the value of the head then destroy it
template <class T>
T Queue<T>::dequeue (void)
{
	// Save the value of temp for return later
	T t = head->data;

	// Save the memory location of the old head
	Node *tn = head;

	head = head->next;
	if (head != nullptr){
		// If the head is nullptr then it indicates the list is now empty and so there is no node to set the previous value of.
		head->previous = nullptr;
	}

	// Delete the old tail
	delete tn;

	--length;

	// Return the old data value
	return t;
}

// O(1) time complexity appending of the given queue to the end of this queue. Much more efficient than multiple calls
// to enqueue for large queues (Average case time: O(1) vs O(n)).
// Does not update the pos because that would be an O(k) operation where k is
// the length of the queue being appended
template <class T>
void Queue<T>::append (Queue<T>* queue)
{
	if (queue->getLength() == 0) {
		// Decided not to throw an exception because this operation itself while unusual is valid.
		return;
	}

	tail->next = queue->head;
	queue->head->previous = tail;

	length = length + queue->getLength();
}

#endif // QUEUE_HPP
