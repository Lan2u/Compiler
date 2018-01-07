#ifndef TOKENISER_HPP
#define TOKENISER_HPP

// Paul Lancaster

#include <string>
#include <unordered_map>
#include "../DataStructures/doubleLinkedList.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include "token.hpp"
#include "../DataStructures/queue.hpp"
#include <vector>
#include <exception>

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

class State_Not_Found_Exception : public std::exception {
	virtual const char* what() const throw() {
		return "The state wasn't found!";
	}
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
	Tokeniser(void);
	Tokeniser(std::string fsaDefinitionFilePath);
	// Adds a transition to the tokeniser. Generates the states as needed.
	void addTransition(std::string);
	void addTransition(std::string,std::string,std::string,std::string);
	Token* tokeniseString(std::string);
	// Sets the initial state. 
	unsigned getNumberOfStates();
	void setInitialState(std::string stateId);
	void reset();
};

#endif // TOKENISER_HPP
