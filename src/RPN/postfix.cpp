// postfix.c
// Paul Lancaster and Eva Lott
// Created	29/12/17
// Edited	29/12/17
// Function definitions for class Postfix

#include "postfix.hpp"

// Checks if a given char denotes a number
bool Postfix::isNumber (char c)
{
	return (c >= 48 && c <= 57);
}


// Gets the precidence of a given operator in string form
unsigned Postfix::getOperatorPrecidence (Operator opr){
	switch (opr) {
	case NEGATION: // !
		return precidence.NEGATION;
	case REMAINDER: // %
		return precidence.REMAINDER;
	case AND: // &
		return precidence.AND;
	case MULTIPLICATION: // *
		return precidence.MULTIPLICATION;
	case ADDITION: // +
		return precidence.ADDITION;
	case SUBTRACTION: // -
		return precidence.SUBTRACTION;
	case DIVISION: // /
		return precidence.DIVISION;
	case COMPARISON: // <
		return precidence.COMPARISON;
	case EQUALS: // =
		return precidence.EQUALS;
	case POWER: // ^
		return precidence.POWER;
	case OR: // |
		return precidence.OR;
	default:
		return -1;
	}
}

// Returns true if opr1 has a higher precidence than opr2
bool Postfix::comparePrecendence (std::string opr1, std::string opr2)
{

}

// Returns a queue with an postfix expression from a string in an infix expression
Queue<std::string> Postfix::convertToPostfix (std::string str)
{
}
