#ifndef POSTFIX_HPP
#define POSTFIX_HPP
// postfix.hpp
// Paul Lancaster and Eva Lott
// Created	29/12/17
// Edited	29/12/17
// Responisble for conversion of string infix sequences into postfix and solving postfix (rpn) expressions. The precendence of operators is as follows...
// Brackets>Powers>Order>Division>Multiplication>Addition>Subtraction

#include "../DataStructures/queue.hpp"
#include "../Tokeniser/Token/operator.hpp"

#include <string>

// Static class Postfix
class Postfix {
public:
	static bool comparePrecendence (Operator*, Operator*);
	static unsigned convertToPostfix (std::string, unsigned, unsigned, Queue<void*>*);
	static bool isNumber (char);
};

#endif // POSTFIX_HPP
