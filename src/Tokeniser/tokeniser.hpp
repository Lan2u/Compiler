#ifndef TOKENISER_HPP
#define TOKENISER_HPP

#define ACCEPTING_TOKEN "*"

// Paul Lancaster

#include <string>
#include <unordered_map>
#include "../Data Structures/doubleLinkedList.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include "token.hpp"
#include "../Data Structures/queue.hpp"
#include <vector>

// Representation of a state within the nFSA. 
class State {
private:
	// Represents the state transition function of the FSA for this state
	std::unordered_map<char, State*> transitions;
	std::string stateId;
	Token* acceptingTokenType;
public:
	std::string getId() { return stateId; };
	State(std::string id);
	void addTransition(char, State*);
	State* getNext(char);
	void setAccepting(Token*);
	bool isAccepting();
	Token* getInstanceOfToken(); // TODO. Should return a new instance of the token that is recognised by reaching this state.
};

/* Container for the states. This relys on the objects being pointers to states. Bad things happen if they aren't.
Abstracted out so can be modified as needed to improve performance later.
Currently backed by a doubly linked list.
*/
class StateContainer : private DoubleLinkedList<State*> {
public:
	StateContainer(void);
	/*Find the state within the state container that has the given id or return a nullptr*/
	State* findStateById(std::string);
	/* Find 2 states by the id within the state container. 
	Has at worst n time complexity rather than 2n for doing a findStateById() call twice. */
	std::vector<State*> findStatesById(std::string, std::string);
	int getLength();
	void add(State*);
};

/*
An nFSA based tokeniser.
*
*/
class Tokeniser {
private:
	State * initialState;
	State * currentState;

	/* A list of all the states in the fsa in the tokeniser. This information could be got by doing a state traversal however that
	is an O(n) operation which is very slow if this needs to be done for each new state as this would cause O(n^2) complexity. */
	StateContainer states;
	Token * getAcceptingTokenType(std::string);
public:
	Tokeniser(std::string fsaDefinitionFilePath);
	// Adds a transition to the tokeniser. Generates the states as needed.
	void addTransition(std::string);
	Token* tokeniseString(std::string);
	void reset();
};
#endif // TOKENISER_HPP
