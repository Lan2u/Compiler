// tester_main.cpp
// Eva Lott
// Created	29/12/17
// Edited	29/12/17
// A file with a main method purely for test code

#include "RPN/postfix.hpp"

int main (void)
{
	std::string meh = "5 + 5 + 5";
	Postfix::convertToPostfix(meh);
}
