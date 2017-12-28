#include <stdio.h>
#include "Stack.h"

void stack_create(stack* stack) {
	stack->size = 0;
	stack->top = NULL;
}

void stack_push(stack* stack, void* element) {
	StackNode *n = malloc(sizeof(*n));
    n->element = element;

	if (stack->top == NULL) {
		stack->top = n;
	} else {
		n->next = stack->top;
		stack->top = n;
    }

	stack->size++;
}

void* stack_pop(stack* stack) {
    if (stack->top == NULL){
        return NULL;
    }

	StackNode *topNode = stack->top;
	
	if (topNode->next = NULL) {
		stack->top = NULL;
	}
	else {
		stack->top = stack->top->next;
		stack->size--;
	}

    return topNode->element;
}

void* stack_top(stack* stack){
	return stack->top->element;
}

int stack_size(stack* stack) {
    return stack->size;
}

bool stack_empty(stack * stack)
{
	return (stack->top == NULL);
}
