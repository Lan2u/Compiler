#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include "queue.hpp"
#include "../Tokeniser/Token/token.hpp"

template <class T>
class BinaryTree {
private:
	class Node {
	public:
		Node *left, *right;

		Node (T);
		Queue<T*>* getPostfixRepresentation (void);

		// Getters
		T* getElement(void) const {return element;};

	private:
		T *element;

	} root;

public:
	BinaryTree (void);
	~BinaryTree (void);

	Queue<T*>* getPostfixRepresentation (void);
	bool add (T*);
	bool remove (T*);
};

template <class T>
Queue<T*>* BinaryTree<T>::Node::getPostfixRepresentation (void)
{
	Queue<Token*> *queue = new Queue<Token*>;

	if (left != nullptr) {
		queue->enqueue(left->getPostfixRepresentation());
	}
	if (right != nullptr) {
		queue->enqueue(right->getPostfixRepresentation());
	}

	queue->enqueue(this.getElement());
	return queue;
}

template <class T>
Queue<T*>* BinaryTree<T>::getPostfixRepresentation (void)
{
	return root->getPostfixRepresentation();
}

// Returns true if successful and false if not
template <class T>
bool add (T *element)
{
	
}

#endif // BINARY_TREE_HPP
