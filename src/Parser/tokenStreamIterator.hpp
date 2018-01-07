#ifndef TOKENSTREAMITERATOR_HPP
#define TOKENSTREAMITERATOR_HPP
#include "../Tokeniser/token.hpp"

// TODO
// Iterates over the token stream keeping track of the current position. This is required for the recusrive descent parser.
class TokenStreamIterator {
	// TODO
public:
	TokenStreamIterator(Token* stream);
	unsigned getPos(); // Get the absolute position in the stream where 0 is the first token
	void setPos(unsigned pos); // Set the absolute position in the stream.
};

#endif // TOKENSTREAMITERATOR_HPP
