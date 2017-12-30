#include "../RPN/list.hpp"
#include "../Tokeniser/token.hpp"
class Node {
public:
	Node* left;
	Node* right;
};

class Tree {
private:
	Node root;
public:
	Token * getPostfixRepresentation(); // TODO (See RPN)
	
};