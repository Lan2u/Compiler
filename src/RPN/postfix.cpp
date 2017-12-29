// postfix.cpp
// Paul Lancaster and Eva Lott
// Created	29/12/17
// Edited	29/12/17
// Function definitions for class Postfix

#include "postfix.hpp"

#define BRACKET_OPEN_SYMBOL 40
#define BRACKET_CLOSE_SYMBOL 41

// Checks if a given char denotes a number
bool Postfix::isNumber (char c)
{
	return (c >= 48 && c <= 57);
}

// Returns true if opr1 has a higher precidence than opr2
bool Postfix::comparePrecendence (Operator opr1, Operator opr2)
{
	return (opr1.getPrecidence > opr2.getPrecidence);
}

// Appends the postfix expression of the given infix character stream to the given output queue. Returns the last index of the stream read.
unsigned Postfix::convertToPostfix (char* tokenStream, unsigned expressionStart, unsigned expressionEnd, std::queue<char>* output)
{
	std::stack<char> operatorStack;

	for (int i = expressionStart; i <= expressionEnd; i++) {
		if (isNumber(*(tokenStream + i))) {
			// If a number it is queued straightaway
			output->push(*(tokenStream + i));
		}
		else if (*(tokenStream + i) == BRACKET_OPEN_SYMBOL) { // (
												   // Recurse since the next part of the equation is in brackets. 
												   // The braket itself is skipped.
			i = convertToPostfix(tokenStream, i + 1, expressionEnd, output);
		}
		else if (*(tokenStream + i) == BRACKET_CLOSE_SYMBOL) { // )
												   // End expresison since the bracket part of the equation has ended. 
												   // This should never be reached if there hasn't been a preceeding '('. 
												   // This should be checked at the tokenisation/recognition/parsing stages.
			while (operatorStack.size > 0) { // Pop the remainder of the stack to the output
				char c = operatorStack.pop;
				 
				output->push;
			}
			return i;

		}
		else {
			while (operatorStack.size > 0) { // Kick off all equal or higher precedence operators
				char stackOperator = operatorStack.pop;
				if (!comparePrecendence(*(tokenStream + i), stackOperator)) {
					output->push(stackOperator);
				}
				else {
					operatorStack.push(stackOperator);
					break;
				}
			}
			operatorStack.push(*(tokenStream + i));
		}
	}
	while (operatorStack.size > 0) { // Pop the remainder of the stack to the output
		output->push(operatorStack.pop);
	}
	return expressionEnd;
}
