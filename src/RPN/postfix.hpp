#ifndef POSTFIX_HPP
#define POSTFIX_HPP
// postfix.hpp
// Paul Lancaster and Eva Lott
// Created	29/12/17
// Edited	29/12/17
// Responisble for conversion of string infix 
// sequences into postfix and solving postfix (rpn)
// expressions. The precendence of operators is as follows...
// Brackets Powers Order Division Multiplication Addition Subtraction

#include "list.hpp"

#include <string>

// Constants for order of operations
// Static class Postfix
class Postfix {
private:
	// Constant struct to remember precidence
	const static struct {
		unsigned short DIVISION = 4;
		unsigned short MULTIPLICATION = 4;
		unsigned short REMAINDER = 4;
		unsigned short ADDITION = 3;
		unsigned short SUBTRACTION = 3;
		unsigned short POWER = 5;
		unsigned short EQUALS = 0;
		unsigned short NEGATION = 1;
		unsigned short AND = 1;
		unsigned short OR = 1;
		unsigned short COMPARISON = 2;
	} precidence;

	bool isNumber (char);

public:
	static unsigned getOperatorPrecidence (Operator);
	static bool comparePrecendence (std::string, std::string);
	static Queue<std::string> convertToPostfix (std::string);
};

enum Operator {
	DIVISION, MULTIPLICATION, REMAINDER, ADDITION, SUBTRACTION, POWER, EQUALS, NEGATION, AND, OR, COMPARISON
};

#endif // POSTFIX_HPP
