#include "../RPN/list.hpp"
#include "../Tokeniser/token.hpp"
template <class T>
class Node {
public:
	Node<T>* left;
	Node<T>* right;
	Queue<T*>* getPostfixRepresentation();
	T* getElement() {return element};
private:
	T* element;
};

template <class X>
class BinaryTree {
private:
	Node<X> root;
public:
	Queue<X*>* getPostfixRepresentation();
	void add(X*);
	void remove(X*);
};
