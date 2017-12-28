#ifndef RPN
#define RPN
#include "Stack.h"
#include "Queue.h"
#include <stdbool.h>

void printQueue(queue* queue);
unsigned int convertToRPN(char* expressionTokenStream, unsigned int expressionStart, unsigned int expressionEnd, queue* output);
int compareOperatorPrecedence(char* c1, char* c2);
int getOperatorPrecedence(char* c);
bool isNumber(char c);

#endif