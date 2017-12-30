#include "tokeniser.hpp"


Tokeniser::Tokeniser(std::string fsaDefinitionFilePath){
	std::ifstream* fsaFileStream = new std::ifstream(fsaDefinitionFilePath);
	if (!fsaFileStream->good()) {
		// TODO File stream error
	}



	std::string definitionLine;
	while (std::getline(fsaFileStream, definitionLine)) {

	}

}

Queue<Token>* Tokeniser::tokeniseString(std::string)
{
	
}

State::State(int id, bool accepting)
{

}

void State::addTransition(std::string, State *)
{
}

State * State::getNext(std::string)
{
	return nullptr;
}
