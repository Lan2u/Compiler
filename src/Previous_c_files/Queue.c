#include "Queue.h"

void queue_create(queue * q)
{
	q->size = 0;
	q->front = NULL;
	q->back = NULL;
}

bool queue_empty(queue * q)
{
	return (q->front == NULL);
}

void * queue_dequeue(queue * q)
{
	if (queue_empty(q)) {
		return NULL;
	}

	QueueNode *n = q->front;

	if (n->previous == NULL) {
		q->front = NULL;
		q->back = NULL;
	}
	else {
		q->front = q->front->previous;
	}

	return n->element;
}

void queue_enqueue(queue * q, void * element)
{
	QueueNode *n = malloc(sizeof(*n));
	n->element = element;
	if (q->size > 0) {
		n->next = q->back;
		n->previous = NULL;
		q->back->previous = n;
	}
	else {
		n->next = NULL;
		n->previous = NULL;
		q->front = n;
		q->back = n;
	}

	q->size++;
}

unsigned int queue_size(queue * q)
{
	return q->size;
}

void * queue_front(queue * q)
{
	return q->front;
}