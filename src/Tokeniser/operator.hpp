#ifndef OPERATOR_HPP
#define OPERATOR_HPP
// operator.hpp
// Eva Lott
// Created	29/12/17
// Edited	29/12/17
// Operator class responsible for defining operators of various types

class Operator {
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
	char symbol;

public:
	Operator (char);
	
	// Getters
	Type getType (void) const {return type;};
	Precidence getPrecidence (void) const {return precidence;};
	char getSymbol (void) const {return symbol;};
};

#endif // OPERATOR_HPP
