#ifndef TREE_HPP
#define TREE_HPP

#include "../Data Structures/data_structures.hpp"
#include "../Tokeniser/token.hpp"

/*
template <class T>
class Node {
public:
	Node<T>(void); // If you want a constructor for the case where no parameter is given on object initialisation

	// NOTE : a function declaration in C++ is somewhat interesting. If you declare a function with foo() then initialise and object with foo(anydatatype),
	// as long as foo hasn't got an alternate constructor to work with foo(anydatatype), foo() will be used.
	// To ensure safety it's standard to declare with foo(void) which ensures that when foo() is declared it will run the foo(void) constructor,
	// ensuring foo(anydatatype) will only work with constructors of foo(anydatatype);
	
	Node<T>(T) {
		element = ele;
		left = nullptr;
		right = nullptr;
	};
	Node<T>* left;
	Node<T>* right;
	Queue<T*>* getPostfixRepresentation(void) {
		Queue<Token*>* queue = new Queue<Token*>;
		if (left != nullptr) {
			queue->push(left->getPostfixRepresentation());
		}
		if (right != nullptr) {
			queue->push(right->getPostfixRepresentation());
		}
		queue->push(this.getElement());
		return queue;
	};
	T* getElement(void) const {return element;};
private:
	T* element;
};

template <class X>
class BinaryTree {
private:
	Node<X> root;
public:
	BinaryTree(void);
	Queue<X*>* getPostfixRepresentation(void) {
		return root->getPostfixRepresentation();
	};
	void add(X*);
	void remove(X*);
};
*/

#endif // TREE_HPP
