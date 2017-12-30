#include "tokeniser.hpp"

#define FSA_DEF_DELIMITER ","

State* Tokeniser::findState(std::string id, std::list<state> ) {
	
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
		std::string accepting;
		
		strStream >> initialStateId;
		strStream >> input;
		strStream >> finalStateId;
		
		// TODO handle there not being 4 pieces of the definition
		strStream >> accepting;

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

		if (accepting == ACCEPTING_TOKEN) {
			finalState->setAccepting(true);
		}

		initialState->addTransition(input, finalState);
	}

}

Queue<Token>* Tokeniser::tokeniseString(std::string)
{
	
}

State::State(std::string id)
{

}

void State::setAccepting(bool accepting) {
	acceptingState = accepting;
}

void State::addTransition(std::string, State *)
{
}

State * State::getNext(std::string)
{
	return nullptr;
}
