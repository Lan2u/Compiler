#include "token.hpp"
#include "operator.hpp"
#include "identifier.hpp"

// The strings that represent the various tokens within the fsa definition file
#define MULTIPLIY_STR_REPRESENTATION "MULTIPLY"
#define IDENTIFIER_STR_REPRESENTATION "IDENTIFIER"

void Token::setValue(std::string val)
{
	value = val;
}

// Returns the relevant token parsed from the given token string representation
Token* Token::getRelevantToken(std::string tokenStrRepresentation) {
	if (tokenStrRepresentation == MULTIPLIY_STR_REPRESENTATION) {
		Token* multOpr = new Operator(Operator::Type::MULTIPLICATION);
		return multOpr;
	}
	else if (tokenStrRepresentation == IDENTIFIER_STR_REPRESENTATION) {
		return new Identifier();
	}
}