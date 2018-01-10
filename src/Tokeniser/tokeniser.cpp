#include "tokeniser.hpp"
// Paul Lancaster and Eva Lott 

#define FSA_DEF_DELIMITER ","

// Get the token that is represented by the given token type string. Eg. OPERATOR would give a token of OPERATOR type. 
Token* Tokeniser::getAcceptingTokenType(std::string tokenTypeStr, std::string value) {
	Token* token = Token::getRelevantToken(tokenTypeStr); // Get the token the corresponds to the token string
	token->setValue(value);  // Attach the value to the token
	return token;
}

Tokeniser::Tokeniser(std::string fsaDefinitionFilePath){	
	std::ifstream fsaFileStream(fsaDefinitionFilePath);
	if (!fsaFileStream.good()) {
		// TODO File stream error
		return;
	}

	for (std::string definitionLine; std::getline(fsaFileStream, definitionLine); ) {
		addTransition(definitionLine);
	}

}

void Tokeniser::addTransition(std::string initialStateId, std::string input, std::string finalStateId, std::string acceptingTokenTypeStr) {
	State* initialState = states.findStateById(initialStateId);
	if (initialState == nullptr) {
		initialState = new State(initialStateId);
		states.add(initialState);
	}

	State* finalState = states.findStateById(finalStateId);
	if (finalState == nullptr) {
		finalState = new State(finalStateId);
		states.add(finalState);
	}

	if (acceptingTokenTypeStr != "") {
		finalState->setAccepting(acceptingTokenTypeStr);
	}

	initialState->addTransition(input.at(0), finalState);
}

void Tokeniser::addTransition(std::string transitionStr)
{
	std::vector<std::string> splitVec;
	boost::split(splitVec, transitionStr, boost::is_any_of(FSA_DEF_DELIMITER));
	int capacity = splitVec.capacity();

	if (capacity == 3) {
		addTransition(splitVec.at(0), splitVec.at(1), splitVec.at(2), "");
	}
	else if (capacity == 4) {
		addTransition(splitVec.at(0), splitVec.at(1), splitVec.at(2), splitVec.at(3));
	}
	else {
		// TODO malformed FSA def handeling.
	}
}

// Tokenises the given string and returns the tokenised result.
Token* Tokeniser::tokeniseString(std::string str)
{
	reset();
	for (int i = 0; i < str.length(); i++) {
		currentState = currentState->getNext(str.at(i));
	}
	
	if (currentState->isAccepting()) {
		return getAcceptingTokenType(currentState->getAcceptingTokenTypeStr(), str);
	}
	else {
		// TODO invalid token encountered
		exit(EXIT_FAILURE);
	}
}

Tokeniser::Tokeniser(void) {
	reset();
}

unsigned Tokeniser::getNumberOfStates()
{
	return states.getLength();
}

void Tokeniser::setInitialState(std::string stateId){
	State* initState = states.findStateById(stateId);
	initialState = initState;
}

void Tokeniser::reset()
{
	currentState = initialState;
}

State::State(std::string id)
{
	stateId = id; 
	acceptingTokenTypeStr = "";
}

// Return true if the state is an accepting state.
bool State::isAccepting() {
	return (acceptingTokenTypeStr == "");
}

std::string State::getAcceptingTokenTypeStr()
{
	return std::string();
}

void State::setAccepting(std::string acceptingTokenStr) {
	acceptingTokenTypeStr = acceptingTokenStr;
}

void State::addTransition(char input, State * finalState)
{
	transitions.insert({ input, finalState });
}

State * State::getNext(char input)
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

/*
Instansiate a new StateContainer.
*/
StateContainer::StateContainer (void) {
	length = 0;
	head = nullptr;
	tail = nullptr;
}


/* Finds the given state in the list */
/* Throws a State_Not_Found_Exception if the state is not found */
State * StateContainer::findStateById(std::string id) {
	Node *node = head;
	while (node != nullptr) {
		if (node->state->getId() == id) {
			return node->state;
		}
		node = node->next;
	}
	throw new State_Not_Found_Exception;
}

/* Finds the 2 states which have the given id's and returns them in a vector in order
with the first element of the returned vector corresponding to the first id and visa versa.
If one of the states is not found then it will be represented by a nullptr */
std::vector<State*> StateContainer::findStatesById(std::string id1, std::string id2)
{
	std::vector<State*> result;
	
	Node* node = head;

	State* state1 = nullptr;
	State* state2 = nullptr;

	while (node != nullptr && (state1 == nullptr || state2 == nullptr)) {
		if (node->state->getId() == id1) {
			state1 = node->state;
		}
		else if (node->state->getId() == id2) {
			state2 = node->state;
		}
		node = node->next;
	}

	result.push_back(state1);
	result.push_back(state2);

	return result;
}

long long unsigned StateContainer::getLength()
{
	return length;
}

/* Add the given state to the state container. Makes no check for duplicate */
void StateContainer::add(State * state)
{
	Node node(state);
	node.next = nullptr;

	if (head == nullptr) {
		head = &node;
		tail = head;
	}
	else {
		tail->next = &node;
	}

	length++;
}
