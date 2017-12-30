#include "../RPN/list.hpp"
#include "../Tokeniser/token.hpp"
#include "tokenStreamIterator.hpp"
#include "tree.hpp"

class Parser {
public:
	// Parses the given token stream and returns the produced parse tree. 
	Tree parseTokenStream(Token* tokenStream); // TODO
};

class Declaration {
public:
	// Return true if the given non-terminal is recognised in the token stream and false if not. 
	// The token stream is reset to the starting position if not recognised.
	bool static recognise(TokenStreamIterator*);
};

class Number {
public:
	bool static recognise(TokenStreamIterator*);
};

class Operator {
public:
	bool static recognise(TokenStreamIterator*);
};