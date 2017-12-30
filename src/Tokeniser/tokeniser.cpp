#include "tokeniser.hpp"

#define FSA_DEF_DELIMITER ","

// Find the state with the given id in the list of states and return a pointer to it or a nullptr if not found
State* Tokeniser::findState(std::string id, List<State*>* states) {
	// TODO implement
	return nullptr;
}

// Get the token that is represented by the given token type string. Eg. OPERATOR would give a token of OPERATOR type. 
// Initially this is statically hard coded however it should probably be stored in a file
Token* Tokeniser::getAcceptingTokenType(std::string tokenTypeStr) {
	// TODO
	return nullptr;
}

Tokeniser::Tokeniser(std::string fsaDefinitionFilePath){	
	std::ifstream fsaFileStream(fsaDefinitionFilePath);
	if (!fsaFileStream.good()) {
		// TODO File stream error
		return;
	}

	List<State*> states; // TODO Replacing with a map will be more efficient however it is not a priority.

	for (std::string definitionLine; std::getline(fsaFileStream, definitionLine); ) {
		// Parse the state
		std::stringstream strStream(definitionLine);
		
		std::string initialStateId;
		std::string input;
		std::string finalStateId;
		std::string acceptingTokenTypeStr;
		
		strStream >> initialStateId;
		strStream >> input;
		strStream >> finalStateId;
		
		// TODO handle there not being 4 pieces of the definition
		strStream >> acceptingTokenTypeStr;

		State* initialState = findState(initialStateId);
		if (initialState == nullptr) {
			initialState = new State(initialStateId);
			states.push(initialState);
		}

		State* finalState = findState(finalStateId);
		if (finalState == nullptr) {
			finalState = new State(finalStateId);
			states.push(finalState);
		}

		
		if (acceptingTokenTypeStr != "") {
			Token* tokenType = getAcceptingTokenType(acceptingTokenTypeStr);
			finalState->setAccepting(tokenType);
		}
		
		

		initialState->addTransition(input, finalState);
	}

}

// Tokenises the given string and returns the tokenised result.
Token* Tokeniser::tokeniseString(std::string str)
{
	reset();
	for (int i = 0; i < str.length; i++) {
		currentState = currentState->getNext(str.at[i]);
	}
	
	if (currentState->isAccepting()) {
		Token* token = currentState->getToken();
		token->getValue = str;
		return token;
	}
	else {
		// TODO invalid token encountered
		exit(EXIT_FAILURE);
	}
}

void Tokeniser::reset()
{
	currentState = initialState;
}

State::State(std::string id)
{
	stateId = id; 
	acceptingTokenType = nullptr;
}

// Return true if the state is an accepting state.
bool State::isAccepting() {
	return (acceptingTokenType != nullptr);
}

void State::setAccepting(Token* type) {
	acceptingTokenType = type;
}

void State::addTransition(std::string input, State * finalState)
{
	transitions.insert({ input, finalState });
}

State * State::getNext(std::string input)
{
	State* next = transitions[input];
	if (next == nullptr) {
		// No registered/defined input->final transition indicates that the input has no effect and the state doesn't change.
		return this;
	}
	else {
		return next;
	}
}
