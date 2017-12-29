// postfix.cpp
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
unsigned Postfix::getOperatorPrecidence (std::string opr)
{
}

// Returns true if opr1 has a higher precidence than opr2
bool Postfix::comparePrecendence (std::string opr1, std::string opr2)
{
}

// Returns a queue with an postfix expression from a string in an infix expression
Queue<void*> Postfix::convertToPostfix (std::string str)
{
}
