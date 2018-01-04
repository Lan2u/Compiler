#ifndef TOKENISER_HPP
#define TOKENISER_HPP

#define ACCEPTING_TOKEN "*"

// Paul Lancaster

#include <string>
#include <unordered_map>
#include "../Data Structures/data_structures.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include "token.hpp"

// Representation of a state within the nFSA. 
class State {
private:
	// Represents the state transition function of the FSA for this state
	std::unordered_map<char, State*> transitions;
	std::string stateId;
	Token* acceptingTokenType;
public: 
	State(std::string id);
	void addTransition(char, State*);
	State* getNext(char);
	void setAccepting(Token*);
	bool isAccepting();
	Token* getInstanceOfToken(); // TODO. Should return a new instance of the token that is recognised by reaching this state.
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
	List<State*> states;

	/* Finds the given state in the list */
	State * Tokeniser::findState(std::string);
	Token * getAcceptingTokenType(std::string);
public:
	Tokeniser(std::string fsaDefinitionFilePath);
	// Adds a transition to the tokeniser. Generates the states as needed.
	void addTransition(std::string);
	Token* tokeniseString(std::string);
	void reset();
};
#endif // TOKENISER_HPP
