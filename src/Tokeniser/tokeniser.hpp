#ifndef TOKENISER_HPP
#define TOKENISER_HPP

#define ACCEPTING_TOKEN "*"

// Paul Lancaster

#include "token.hpp"
#include <string>
#include <unordered_map>
#include "../RPN/list.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

// Representation of a state within the nFSA. 
class State {
private:
	// Represents the state transition function of the FSA for this state
	std::unordered_map<std::string, State*> transitions;
	std::string stateId;
	Token* acceptingTokenType;
public: 
	State(std::string id);
	void addTransition(std::string, State*);
	State* getNext(std::string);
	void setAccepting(Token*);
	bool isAccepting();
	Token* getToken() { return acceptingTokenType; }
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
