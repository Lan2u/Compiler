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
	State * Tokeniser::findState(std::string, List<State*>*);
	Token * getAcceptingTokenType(std::string);
public:
	Tokeniser(std::string fsaDefinitionFilePath);
	Token* tokeniseString(std::string);
	void reset();
};
#endif // TOKENISER_HPP
