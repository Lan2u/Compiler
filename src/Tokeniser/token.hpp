#ifndef TOKEN_HPP
#define TOKEN_HPP
// Eva Lott, Paul Lancaster
// Created	29/12/17
// Token class responsible for defining tokens of various types

#include <stdlib.h>
#include <string>

class Token {
protected:
	std::string *value;
public:
	virtual std::string* getValue() = 0;
	void setValue(std::string val) { value = &val; }
};

class Operator : public Token{
private:
	enum class Type {
		DIVISION, MULTIPLICATION, REMAINDER, ADDITION, SUBTRACTION, POWER, EQUALS, NEGATION, AND, OR, COMPARISON
	};
	
	// Constant struct to remember precidence
	enum class Precidence {
		POWER = 5,
		DIVISION = 4,
		MULTIPLICATION = 4,
		REMAINDER = 4,
		ADDITION = 3,
		SUBTRACTION = 3,
		COMPARISON = 2,
		NEGATION = 1,
		AND = 1,
		OR = 1,
		EQUALS = 0
	};

	Type type;
	Precidence precidence;

public:
	Operator (char);
	
	// Getters
	Type getType (void) const {return type;};
	Precidence getPrecidence (void) const {return precidence;};
};

#endif // TOKEN_HPP
