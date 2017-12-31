// tester_main.cpp
// Eva Lott, Paul Lancaster
// Created	29/12/17
// Edited	29/12/17
// A file with a main method purely for test code

#include "RPN/postfix.hpp"
#include "compiler.hpp"
#include <time.h>

int main (void)
{
	Queue<char> *q = new Queue<char>;
	std::string foo = "5 + 5 + 5";
	Postfix::convertToPostfix(foo,0,foo.length(),q);
}

void compileTest(std::string codeFilePath, std::string outFilePath) {
	
	clock_t t = clock();
	compile(codeFilePath, outFilePath);
	t = clock() - t;
	printf("Compile time taken : %d clicks", t);
}