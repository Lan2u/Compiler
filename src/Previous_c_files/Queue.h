#ifndef Queue
#define Queue
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>

struct QueueNode;

typedef struct QueueNode {
	struct QueueNode *next;
	struct QueueNode *previous;
	void* element;
} QueueNode;

typedef struct Queue {
	QueueNode* front;
	QueueNode* back;
	unsigned int size;
} queue;

// Initialise/create the given queue.
void queue_create(queue * q);

// Return true if the queue is empty, false if it is not.
bool queue_empty(queue *q);

// Dequeue the next element from the queue and return it.
void* queue_dequeue(queue *q);

// Enqueue an element to the queue.
void queue_enqueue(queue *q, void *element);

// Return the queue size.
unsigned int queue_size(queue *q);

// Return the front element of the queue without removing.
void* queue_front(queue *q);

#endif