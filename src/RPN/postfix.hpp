#ifndef POSTFIX_HPP
#define	POSTFIX_HPP
// postfix.hpp
// Paul Lancaster and Eva Lott
// Created	29/12/17
// Edited	29/12/17
// Responisble for conversion of string infix 
// sequences into postfix and solving postfix (rpn)
// expressions. The precendence of operators is as follows...
// Brackets Powers Order Division Multiplication Addition Subtraction

#include "list.hpp"

#include <iostream>
#include <string>

// Constants for order of operations
#define	DIVISION_PRECEDENCE			4
#define	MULTIPLICATION_PRECEDENCE	4
#define	REMAINDER_PRECEDENCE		4
#define	ADDITION_PRECEDENCE			3
#define	SUBTRACTION_PRECEDENCE		3
#define	POWER_PRECEDENCE			5
#define	EQUALS_PRECEDENCE			0
#define	NEGATION_PRECEDENCE			1
#define	AND_PRECEDENCE				1
#define	OR_PRECEDENCE				1
#define	COMPARISON_PRECEDENCE		2

// Staic class Postfix
class Postfix {
public:
	static bool isNumber(char);
	static unsigned convertToPostFix (std::string, Queue<std::string>);
};


#endif // POSTFIX_HPP
