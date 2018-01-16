#include "tokenStreamIterator.hpp"

TokenStreamIterator::TokenStreamIterator(void)
{
	currentNode = nullptr;
	headNode = nullptr;
	currentLength = 0;
	currentPosition = -1;
}

void TokenStreamIterator::queueToken(Token *token)
{
	Node *newNode = new Node(token);

	if (headNode == nullptr) {
		newNode->previous = nullptr;
		headNode = newNode;
		tailNode = headNode;
		headNode->next = nullptr;
		currentPosition = 0;
		currentNode = headNode;
	}
	else {
		newNode->previous = tailNode;
		newNode->next = nullptr;
		tailNode->next = newNode;
	}

	currentLength++;
}

void TokenStreamIterator::queueTokens(Queue<Token*>* tokenQueue) {
	while (tokenQueue->getLength() > 0) {
		queueToken(tokenQueue->dequeue());
	}
}

bool TokenStreamIterator::hasNext()
{
	return !(currentNode == nullptr || currentNode->next == nullptr);
}

bool TokenStreamIterator::hasPrevious()
{
	return !(currentNode == nullptr || currentNode->previous == nullptr);
}

Token * TokenStreamIterator::nextToken()
{
	if (!hasNext()) {
		throw No_Token_Found_Exception();
	}

	currentNode = currentNode->next;
	currentPosition++;
	return getToken();
}

Token* TokenStreamIterator::previousToken() {
	if (!hasPrevious()) {
		throw No_Token_Found_Exception();
	}
	
	currentNode = currentNode->previous;
	currentPosition--;
	return getToken();
}

Token * TokenStreamIterator::getToken()
{
	if (currentNode == nullptr) {
		throw No_Token_Found_Exception();
	}
	else {
		return currentNode->element;
	}
}

long long unsigned TokenStreamIterator::remove (void)
{
	if (currentNode == nullptr) {
		throw No_Token_Found_Exception();
	}

	Node *node = currentNode;

	if (hasPrevious() && hasNext()) { // Has previous and next nodes (is in middle).
		currentNode->previous->next = currentNode->next;
		currentNode = currentNode->next;
	}
	else if (hasPrevious()) { // Has previous node but doesn't have a next node (is at end)
		currentNode->previous->next = nullptr;
		currentNode = currentNode->previous;
		currentPosition--;
		
	}
	else if (hasNext()) { // Has a next node but doesn't have a previous node (is at start)
		currentNode->next->previous = nullptr;
		currentNode = currentNode->next;
	}
	else { // Has neither a next node or a previous node (is the only node with a length of 1)
		currentNode = nullptr;
		currentPosition--;
	}

	delete node;
	currentLength--;
	return currentPosition;
}

long long int TokenStreamIterator::getPos(void)
{
	return currentPosition;
}

// Time complexity is bounded by n. Worst case time complexity and average time complexities are O(n). Best case O(1)
bool TokenStreamIterator::setPos(long long int pos)
{
	if (pos > currentLength) {
		return false; // Not possible to set position
	}

	if (pos > currentPosition) {
		while (currentPosition != pos) {
			nextToken();
		}
	}
	else if (pos < currentPosition) {
		while (currentPosition != pos) {
			previousToken();
		}
	}
	return true; // The move was successful.
}
