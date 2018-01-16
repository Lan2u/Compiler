#ifndef TOKENSTREAMITERATOR_HPP
#define TOKENSTREAMITERATOR_HPP
#include "../Tokeniser/Token/token.hpp"
#include "../DataStructures/doubleLinkedList.hpp"
#include "../DataStructures/queue.hpp"

class No_Token_Found_Exception : public std::exception {
public:
	No_Token_Found_Exception(void) : std::exception() {};

	const char* what() const throw() {
		return "No Token Found at the Current Position!";
	}
};

// Iterates over the token stream keeping track of the current position. This is required for the recusrive descent parser.
// Ordering is maintained with first elements being added being the first elements that are going to be used however do not want to remove elements when we do this and want to be able to access
// anywhere in the token stream in certain situations. Each position also needs to have an index so for that reason a double linked list like structure is used not a queue. A double linked list
// cannot just be used because it doesn't have the required methods and the new methods require very tight binding to the underlying nodes and so cannot rely on double linked list exact 
// implementation being always exactly the same.

// This is effectively an interator for a navigatable doubly linked list. It could easily be made more generic using templates but I haven't done this because it isn't yet needed.
class TokenStreamIterator {
private:
	struct Node {
		Node *next = nullptr, *previous = nullptr;
		Token *element;
		Node (Token *element) { this->element = element; }
	} *currentNode, *headNode, *tailNode;

	// The current position and length of the stream.
	long long int currentPosition;
	long long unsigned currentLength;

public:
	// Create a new token stream iterator.
	TokenStreamIterator (void);

	// Add tokens to the token stream iterator
	void queueToken(Token*); // O (1)
	void queueTokens(Queue<Token*>*); // O(k) where k is length of the queue

	// Return true if there is another token after the current position. O(1) in all cases.
	bool hasNext(void);

	// Return true if there is another token before the current position. O(1) in all cases.
	bool hasPrevious(void);

	// Get next token. O(1) in all cases.
	Token* nextToken(void);

	// Get the previous token. O(1) in all cases.
	Token * previousToken(void);

	// Get the token at the current position. O(1)
	Token* getToken(void);

	// Remove the current token from the tokens. Returns the new current position.
	// In the case that the node removed is in the middle or start the returned value will be the same as before but this will be the next node (since the nodes have moved back).
	// In the case that the node removed is at the end the returned value/new current position will be the node previous to the one removed.
	// O(1) time complexity in all cases.
	long long unsigned remove (void);

	// Get the absolute position in the stream where 0 is the first token. -1 indicates the stream is empty.
	long long int getPos(void);

	// Set the absolute position in the stream. Returns true if successful and false if not. If unsuccessful the current position is not moved.  O(n) n=length of token stream
	bool setPos (long long int); 
};

#endif // TOKENSTREAMITERATOR_HP:
