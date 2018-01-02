#ifndef TREE_HPP
#define TREE_HPP

#include "../RPN/list.hpp"
#include "../Tokeniser/token.hpp"

template <class T>
class Node {
public:
	Node<T>(void); // If you want a constructor for the case where no parameter is given on object initialisation

	// NOTE : a function declaration in C++ is somewhat interesting. If you declare a function with foo() then initialise and object with foo(anydatatype),
	// as long as foo hasn't got an alternate constructor to work with foo(anydatatype), foo() will be used.
	// To ensure safety it's standard to declare with foo(void) which ensures that when foo() is declared it will run the foo(void) constructor,
	// ensuring foo(anydatatype) will only work with constructors of foo(anydatatype);
	
	Node<T>(T);
	Node<T>* left;
	Node<T>* right;
	Queue<T*>* getPostfixRepresentation(void);
	T* getElement(void) const {return element;};
private:
	T* element;
};

// NOTE : template class functions are declared in the same header as their associated template class,
// errors will ensue otherwise

template <class T>
Queue<T*>* Node<T>::getPostfixRepresentation(void){
  Queue<Token*>* queue = new Queue<Token*>;
  if (left != nullptr){
    queue->push(left->getPostfixRepresentation());
  }
  if (right != nullptr){
    queue->push(right->getPostfixRepresentation());
  }
  queue->push(this.getElement());
  return queue;
}

template <class T>
Node<T>::Node(T ele){
  element = ele;
  left = nullptr;
  right = nullptr;
}

template <class X>
class BinaryTree {
private:
	Node<X> root;
public:
	BinaryTree(void);
	Queue<X*>* getPostfixRepresentation(void);
	void add(X*);
	void remove(X*);
};

template <class X>
Queue<X*>* BinaryTree<X>::getPostfixRepresentation(void){
  return root->getPostfixRepresentation();
}

Queue<X*>* BinaryTree::getPostfixRepresentation() {

#endif // TREE_HPP
