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

/*
An nFSA based tokeniser. 
*/
class Tokeniser {
public:
	State * findState(std::string id);
	Tokeniser(std::string fsaDefinitionFilePath);
	Queue<Token>* tokeniseString(std::string);
};

// Representation of a state within the nFSA. 
class State {
private:
	// Represents the state transition function of the FSA for this state
	std::unordered_map<std::string, State*> transitions;
	std::string id;
	bool acceptingState;
public: 
	State(std::string id);
	void addTransition(std::string, State*);
	State* getNext(std::string);
	void setAccepting(bool accepting);
};

#endif // TOKENISER_HPP
