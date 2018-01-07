#ifndef TOKEN_HPP
#define TOKEN_HPP
// Eva Lott, Paul Lancaster
// Created	29/12/17
// Token class responsible for defining tokens of various types

#include <stdlib.h>
#include <string>

class Token {
protected:
	std::string value;
public:
	// Contains every possible unique token type. 
	// Some types may have subtypes if you instansiate a class of that type.
	// TODO -> Unnest from the code as much as possible.
	enum class TokenType {
		OPERATOR, IDENTIFIER 
	};

	void setValue(std::string);
	static Token* getRelevantToken(std::string);
	virtual TokenType getType() = 0;
	virtual std::string getValue() = 0;
};

#endif // TOKEN_HPP
