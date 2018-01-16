#include "tokenStreamIterator.hpp"

TokenStreamIterator::TokenStreamIterator(void)
{
	currentNode = nullptr;
	headNode = nullptr;

	currentLength = 0;
	currentPosition = EMPTY_POS;
}

void TokenStreamIterator::queueToken(Token *token)
{
	Node *newNode = new Node(token);

	if (headNode == nullptr) {
		newNode->previous = nullptr;
		newNode->next = nullptr;

		headNode = newNode;
		tailNode = headNode;

		currentPosition = EMPTY_POS + 1; // The position starts at the empty position + 1 (eg. if the empty pos is 0 then it starts at 1)
		currentNode = headNode;
	}
	else {
		newNode->previous = tailNode;
		newNode->next = nullptr;
		tailNode->next = newNode;
	}

	currentLength++;
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

	return currentNode->element;
}

long long unsigned int TokenStreamIterator::remove (void)
{
	if (currentNode == nullptr) {
		throw No_Token_Found_Exception();
	}

	Node *node = currentNode;

	if (hasPrevious() && hasNext()) { // Has previous and next nodes (is in middle).
		currentNode->previous->next = currentNode->next;
		currentNode = currentNode->next;
		// Leaves position unchanged since the now current node has been moved back when the one before was removed.
	}
	else if (hasPrevious()) { // Has previous node but doesn't have a next node (is at end)
		currentNode->previous->next = nullptr;
		currentNode = currentNode->previous;
		currentPosition--; // Stream has got smaller and so the old position is now out of bounds so move back.
	}
	else if (hasNext()) { // Has a next node but doesn't have a previous node (is at start)
		currentNode->next->previous = nullptr;
		currentNode = currentNode->next;
	}
	else { // Has neither a next node or a previous node (is the only node with a length of 1)
		currentNode = nullptr;
		currentPosition = EMPTY_POS;
	}

	delete node;
	currentLength--;
	return currentPosition;
}

long long unsigned int TokenStreamIterator::getPos(void)
{
	return currentPosition;
}

// Time complexity is bounded by n. Worst case time complexity and average time complexities are O(n). Best case O(1)
bool TokenStreamIterator::setPos(long long unsigned int pos)
{
	if (pos > currentLength || pos == EMPTY_POS) {
		return false; // Not possible to set position to beyond the current length or to the empty position.
	}

	while (currentPosition < pos) {
		nextToken();
	}

	while (currentPosition > pos) {
		previousToken();
	}

	return true; // The move was successful.
}
