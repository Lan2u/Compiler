#ifndef PARSER_HPP
#define PARSER_HPP

#include "tokenStreamIterator.hpp"

class Parser {
public:
	
};

class Recogniser {
public:
	// Return true if the given terminal/non-terminal is recognised in the token stream and false 
	// if not. The token stream is reset to the starting position if not recognised.
	bool recogniseProgram(TokenStreamIterator* tokenStream);
	bool recogniseDeclaration(TokenStreamIterator* tokenStream);
	bool recogniseNumber(TokenStreamIterator* tokenStream);
	bool recogniseOperator(TokenStreamIterator* tokenStream);
};

#endif // PARSER_HPP