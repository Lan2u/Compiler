#ifndef POSTFIX_HPP
#define POSTFIX_HPP
// postfix.hpp
// Paul Lancaster and Eva Lott
// Created	29/12/17
// Edited	29/12/17
// Responisble for conversion of string infix sequences into postfix and solving postfix (rpn) expressions. The precendence of operators is as follows...
// Brackets>Powers>Order>Division>Multiplication>Addition>Subtraction

#include "list.hpp"
#include "../Tokeniser/operator.hpp"

#include <string>

// Static class Postfix
class Postfix {
private:
	bool isNumber (char);

public:
	static bool comparePrecendence (Operator, Operator);
	static Queue<void*> convertToPostfix (std::string);
};

#endif // POSTFIX_HPP
