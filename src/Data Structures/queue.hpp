#ifndef QUEUE
#define QUEUE

#include "doubleLinkedList.hpp"

// Queue derived class
template <class T>
class Queue : private DoubleLinkedList<T> {
public:
	T dequeue(void);
	void enqueue(T);
	void append(Queue<T>*);
	int getLength();
};

template <class T>
int Queue<T>::getLength() {
	return length;
}

// O(1) time complexity appending of the given queue to the end of this queue
// Does not update the pos because that would be an O(k) operation where k is
// the length of the queue being appended
template <class T>
void Queue<T>::append(Queue<T>* queue) {
	queue->head->previous = tail;
	tail->next = queue->head;
	length = length + queue->getLength();
}

// Enqueue an element to the queue.
template <class T>
void Queue<T>::enqueue(T element) {
	push(element);
}

// Pop the value of the head then destroy it
template <class T>
T Queue<T>::dequeue(void)
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

#endif