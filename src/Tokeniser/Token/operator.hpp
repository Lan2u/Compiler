#ifndef TOKEN_OPERATOR_HPP
#define TOKEN_OPERATOR_HPP

#include "token.hpp"

class Operator : public Token {
public:
	enum class Type {
		DIVISION, MULTIPLICATION, REMAINDER, ADDITION, SUBTRACTION, POWER, EQUALS, NEGATION, AND, OR, COMPARISON
	};

	Operator(char);
	Operator(Type);

	// Getters valid to all tokens
	TokenType getType();
	std::string* getValue();

	// Unique Getters to Operator
	Type getOperatorType(void) const { return type; };
	int getPrecidence(void) const { return (int) precidence; };

private:
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
};

#endif // TOKEN_OPERATOR_HPP