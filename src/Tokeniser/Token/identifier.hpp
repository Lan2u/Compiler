#ifndef TOKEN_IDENTIFIER_HPP
#define TOKEN_IDENTIFIER_HPP
#include "token.hpp"

// Represents an identifier such as the 'x' in 'int x = 0'
class Identifier : public Token {
public:
	Identifier() {};
	Identifier(std::string);
	TokenType getType();
	std::string getValue();
};

#endif // TOKEN_IDENTIFIER_HPP