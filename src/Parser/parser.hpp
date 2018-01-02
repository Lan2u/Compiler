#include "../RPN/list.hpp"
#include "../Tokeniser/token.hpp"
#include "tokenStreamIterator.hpp"
#include "tree.hpp"

class Parser {
public:
	// Parses the given token stream and returns the produced parse tree. 
	BinaryTree<Token> parseTokenStream(Token* tokenStream); // TODO
};

class Recogniser {
public:
	// Return true if the given terminal/non-terminal is recognised in the token stream and false 
	// if not. The token stream is reset to the starting position if not recognised.
	bool recogniseDeclaration(Token* tokenStream);
	bool recogniseNumber(Token* tokenStream);
	bool recogniseOperator(Token* tokenStream);

};