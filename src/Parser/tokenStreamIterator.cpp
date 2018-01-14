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
	Node<Token*>* newNode = new Node<Token*>(token);

	if (headNode == nullptr) {
		headNode = newNode;
		tailNode = headNode;
		newNode->previous = nullptr;
		currentPosition = 0;
	}
	else {
		newNode->previous = tailNode;
		tailNode->next = newNode;
		newNode->next = nullptr;
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
	return !(currentNode == nullptr || currentNode->getNext() == nullptr);
}

bool TokenStreamIterator::hasPrevious()
{
	return !(currentNode == nullptr || currentNode->getPrevious() == nullptr);
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
	return currentNode->element;
}

unsigned TokenStreamIterator::remove()
{
	if (currentNode == nullptr) {
		throw No_Token_Found_Exception();
	}

	Node<Token*>* node = currentNode;

	if (hasPrevious() && hasNext()) { // Has previous and next nodes (is in middle).
		currentNode->getPrevious()->next = currentNode->getNext();
		currentNode = currentNode->getNext();
	}
	else if (hasPrevious()) { // Has previous node but doesn't have a next node (is at end)
		currentNode->previous->next = nullptr;
		currentNode = currentNode->getPrevious();
		currentPosition--;
		
	}
	else if (hasNext()) { // Has a next node but doesn't have a previous node (is at start)
		currentNode->next->previous = nullptr;
		currentNode = currentNode->getNext();
	}
	else { // Has neither a next node or a previous node (is the only node with a length of 1)
		currentNode = nullptr;
		currentPosition--;
	}

	delete node;
	currentLength--;
	return currentPosition;
}

int TokenStreamIterator::getPos()
{
	return currentPosition;
}

// Time complexity is bounded by n. Worst case time complexity and average time complexities are O(n). Best case O(1)
bool TokenStreamIterator::setPos(int pos)
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
