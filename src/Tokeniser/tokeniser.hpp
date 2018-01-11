#ifndef TOKENISER_HPP
#define TOKENISER_HPP

// Paul Lancaster and Eva Lott

#include <string>
#include <unordered_map>
#include "../DataStructures/doubleLinkedList.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include "Token/token.hpp"
#include "../DataStructures/queue.hpp"
#include <vector>
#include <exception>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>

// Representation of a state within the nFSA. 
class State {
private:
	std::unordered_map<char, State*> transitions; // Keeps tracks of which input (char) causes which next state.
	std::string stateId; // The id of the state. Should be unique.
	std::string acceptingTokenTypeStr; // The string that represents the token that this state represents if it was accepted as a token
public:
	// Constructor. The given id should be unique otherwise the behaviour of the whole program is undefined.
	State(std::string id);

	// Methods used for traversing the states once the FSA has been created/generated
	State* getNext(char);
	bool isAccepting();

	// Methods used for building up the states when the FSA is created.
	void addTransition(char, State*); 
	void setAccepting(std::string);
	
	// Getters
	std::string getAcceptingTokenTypeStr();
	std::string getId() const { return stateId; };
};

class State_Not_Found_Exception : public std::exception {
	virtual const char* what() const throw() {
		return "The state wasn't found!";
	}
};

/* Container for the states. This relys on the objects being pointers to states. Bad things happen if they aren't.
Abstracted out so can be modified as needed to improve performance later.
Currently backed by a doubly linked list.
*/
class StateContainer{
private:
	long long unsigned length;
	struct Node {
		Node *next;
		State *state;
		Node (State *state) {
			this->state = state;
			next = nullptr;
		}
	} *head, *tail;
	DoubleLinkedList<State*> states;
public:
	StateContainer(void);
	~StateContainer(void);
	/*Find the state within the state container that has the given id or return a nullptr*/
	State* findStateById(std::string);
	/* Find 2 states by the id within the state container. 
	Has at worst n time complexity rather than 2n for doing a findStateById() call twice. */
	std::vector<State*> findStatesById(std::string, std::string);
	long long unsigned getLength (void);
	void add(State*);
};

/*
* An nFSA based tokeniser.
*/
class Tokeniser {
private:
	State * initialState;
	State * currentState;

	/* A list of all the states in the fsa in the tokeniser. This information could be got by doing a state traversal however that
	is an O(n) operation which is very slow if this needs to be done for each new state as this would cause O(n^2) complexity. */
	StateContainer states;
	Token* getAcceptingTokenType(std::string, std::string);
public:
	Tokeniser(void);
	Tokeniser(std::string fsaDefinitionFilePath);

	// Adds a transition to the tokeniser. Generates the states as needed.
	void addTransition(std::string);
	void addTransition(std::string,std::string,std::string,std::string);
	Token* tokeniseString(std::string);

	// Sets the initial state. 
	unsigned long long getNumberOfStates();
	void setInitialState(std::string stateId);
	void reset();
};

#endif // TOKENISER_HPP
