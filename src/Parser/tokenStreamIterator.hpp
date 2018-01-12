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
	template <class T>
	class Node {
	public:
		Node* next;
		Node* previous;
		T element;
		Node(T element) {
			next = nullptr;
			previous = nullptr;
			Node::element = element;
		};
		Node* getNext() {
			return next;
		};
		Node* getPrevious() {
			return previous;
		};
	};

	// The current, head and tail nodes.
	// Could of made it circular but didn't as the added simpilicity of the hasPrevious() method is worth the small extra space cost.
	Node<Token*>* currentNode;
	Node<Token*>* headNode; // Always position 0
	Node<Token*>* tailNode; // Always position length - 1

	// The current position and length of the stream.
	int currentPosition;
	unsigned currentLength;

public:
	// Create a new token stream iterator.
	TokenStreamIterator(void);

	// Add tokens to the token stream iterator
	void queueToken(Token*); // O (1)
	void queueTokens(Queue<Token*>*); // O(k) where k is length of the queue

	// Return true if there is another token after the current position. O(1) in all cases.
	bool hasNext();

	// Return true if there is another token before the current position. O(1) in all cases.
	bool hasPrevious();

	// Get next token. O(1) in all cases.
	Token* nextToken();

	// Get the previous token. O(1) in all cases.
	Token * previousToken();

	// Get the token at the current position. O(1)
	Token* getToken();

	// Remove the current token from the tokens. Returns the new current position.
	// In the case that the node removed is in the middle or start the returned value will be the same as before but this will be the next node (since the nodes have moved back).
	// In the case that the node removed is at the end the returned value/new current position will be the node previous to the one removed.
	// O(1) time complexity in all cases.
	unsigned remove();

	// Get the absolute position in the stream where 0 is the first token. -1 indicates the stream is empty.
	int getPos(); 

	// Set the absolute position in the stream. Returns true if successful and false if not. If unsuccessful the current position is not moved.  O(n) n=length of token stream
	bool setPos(int pos); 
};

#endif // TOKENSTREAMITERATOR_HPP
