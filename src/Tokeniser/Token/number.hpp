#ifndef TOKEN_NUMBER_HPP
#define TOKEN_NUMBER_HPP
#include "token.hpp"

class Number : public Token {
public:
	Number(void);
	TokenType getType();
	std::string getValue();
};


#endif // TOKEN_NUMBER_HPP