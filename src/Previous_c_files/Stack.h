#ifndef Stack
#define Stack
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>

struct StackNode;

typedef struct StackNode{
	struct StackNode* next;
    void* element;
} StackNode;

typedef struct Stack {
	unsigned int size;
	StackNode *top;
} stack;

void stack_create(stack* stack);
void stack_push(stack* stack, void* element);
void* stack_pop(stack* stack);
void* stack_top(stack* stack);
int stack_size(stack* stack);
bool stack_empty(stack* stack);

#endif