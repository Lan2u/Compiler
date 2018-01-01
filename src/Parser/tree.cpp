#include "tree.hpp"

Node::Node(T ele){
  element = ele;
  left = nullptr;
  right = nullptr;
}

Queue<T*>* Node::getPostfixRepresentation(){
  Queue<Token*>* queue = new Queue<Token*>();
  if (left != nullptr){
    queue.append(left.getPostfixRepresentation());
  }
  if (right != nullptr){
    queue.append(right.getPostfixRepresentation());
  }
  queue.append(this.getElement());
  return queue;
}

Queue<X*>* BinaryTree::getPostfixRepresentation(){
  return root.getPostfixRepresentation();
}
