#ifndef STACK_HPP
#define STACK_HPP
// stack.hpp
// Paul Lancaster and Eva Lott
// stack C++ implementation

#include "doubleLinkedList.hpp"

// Stack derived class
template <class T>
class Stack : public DoubleLinkedList<T> {
public:
	T pop(void);
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
#endif // STACK_HPP
