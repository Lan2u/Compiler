#include <stdio.h>
#include <stdbool.h>
#include "Stack.h"
#include "Queue.h"
#include "rpn.h"

/*
Brackets Powers Order Division Multiplication Addition Subtraction

Operator : Precedence
%  4
*  4
/  4
+  3
-  3
^  5
!  1
&& 1
&  1
|| 1
|  1
=  5
>  2
*/
#define DIVISION_PRECEDENCE 4
#define MULTIPLICATION_PRECEDENCE 4
#define REMAINDER_PRECEDENCE 4
#define ADDITION_PRECEDENCE 3
#define SUBTRACTION_PRECEDENCE 3
#define POWER_PRECEDENCE 5
#define EQUALS_PRECEDENCE 0
#define NEGATION_PRECEDENCE 1
#define AND_PRECEDENCE 1
#define OR_PRECEDENCE 1
#define COMPARISON_PRECEDENCE 2

void printQueue(queue* queue) {
	while (queue_empty(queue) != true) {
		printf("%c",((char*) queue_dequeue(queue)));
	}
	printf("%n");
}

int main(){
	char tokenStream[] = "4 + 5 * 6";
	unsigned int expressionEnd = 8;
	queue outputQueue;
	queue_create(&outputQueue);

	convertToRPN(tokenStream, 0, expressionEnd, &outputQueue);

	printQueue(&outputQueue);
}

// Returns the final index in the expression token stream that was evaluated. This is either the end (expressionEnd) or the location of a closing bracket.
unsigned int convertToRPN(char* expressionTokenStream, unsigned int expressionStart ,unsigned int expressionEnd, queue* output) {
	stack *stack;
	stack_create(stack);
	for (int i = expressionStart; i <= expressionEnd; i++) {
		if (isNumber(expressionTokenStream[i])) {
			// If a number it is queued straightaway
			queue_enqueue(output, (void *) ( expressionTokenStream + i ));
		}
		else if (expressionTokenStream[i] == 40 ) { // (
			// Recurse since the next part of the equation is in brackets. 
			// The braket itself is skipped.
			i = convertToRPN(expressionTokenStream, i+1, expressionEnd, output);
		}
		else if (expressionTokenStream[i] == 41) { // )
			// End expresison since the bracket part of the equation has ended. 
			// This should never be reached if there hasn't been a preceeding '('. 
			// This should be checked at the tokenisation/recognition/parsing stages.
			while (!stack_empty(stack)) { // Pop the remainder of the stack to the output
				queue_enqueue(output, stack_pop(stack));
			}
			return i;

		} else {
			while (stack_empty(stack) != true) { // Kick off all equal or higher precedence operators
				char* stackOperator = stack_pop(stack);
				if (compareOperatorPrecedence((expressionTokenStream + i), stackOperator) <= 0) {
					queue_enqueue(output, (void*) stackOperator);
				} else {
					stack_push(stack, stackOperator);
					break;
				}
			}
			stack_push(stack, (void*) (expressionTokenStream+i));
		}
	}
	while (!stack_empty(stack)) { // Pop the remainder of the stack to the output
		queue_enqueue(output, stack_pop(stack));
	}
	return expressionEnd;
}

/*  Returns > 0 if c1 has a higher operator precedence (is tighter binding) than c2
	Returns 0 if they have equal operator precedence
	Returns < 0 if c1 has a lower operator precedence than c2

	Eg. '+','-' have lower operator precedence than '*','/'
*/
int compareOperatorPrecedence(char* c1, char* c2) {
	int precedence1 = getOperatorPrecedence(c1);
	int precedence2 = getOperatorPrecedence(c2);

	if (precedence1 < 0) {
		printf("Invalid first operator!");
	}

	if (precedence2 < 0) {
		printf("Invalid second operator!");
	}

	return (precedence1 - precedence2);

}

/* Get the operator precedence where a higher value indicates higher precedence (tighter binding) */
int getOperatorPrecedence(char* c) {
	switch (*c) {
	case 33: // !
		return NEGATION_PRECEDENCE;
	case 37: // %
		return REMAINDER_PRECEDENCE;
	case 38: // &
		return AND_PRECEDENCE;
	case 42: // *
		return MULTIPLICATION_PRECEDENCE;
	case 43: // +
		return ADDITION_PRECEDENCE;
	case 45: // -
		return SUBTRACTION_PRECEDENCE;
	case 47: // /
		return DIVISION_PRECEDENCE;
	case 60: // <
		return COMPARISON_PRECEDENCE;
	case 61: // =
		return EQUALS_PRECEDENCE;
	case 62: // >
		return COMPARISON_PRECEDENCE;
	case 94: // ^
		return POWER_PRECEDENCE;
	case 124: // |
		return OR_PRECEDENCE;
	default:
		return -1;
	}
}

bool isNumber(char c) {
	return (c >= 48 && c <= 57);
}
