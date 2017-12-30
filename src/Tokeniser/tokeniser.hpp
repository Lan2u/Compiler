#ifndef TOKENISER_HPP
#define TOKENISER_HPP

// Paul Lancaster

#include "token.hpp"
#include <string>
#include <unordered_map>
#include "../RPN/list.hpp"
#include <fstream>
#include <iostream>

/*
An nFSA based tokeniser. 
*/
class Tokeniser {
public:
	Tokeniser(std::string fsaDefinitionFilePath);
	Queue<Token>* tokeniseString(std::string);
};

// Representation of a state within the nFSA. 
class State {
private:
	// Represents the state transition function of the FSA for this state
	std::unordered_map<std::string, State*> transitions;
public: 
	State(int id, bool accepting);
	void addTransition(std::string, State*);
	State* getNext(std::string);
};

#endif // TOKENISER_HPP
