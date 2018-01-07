#include "token.hpp"
#include "operator.hpp"

// The strings that represent the various tokens within the fsa definition file
#define MULTIPLIY_STR_REPRESENTATION "MULTIPLY"

// Returns the relevant token parsed from the given token string representation
Token* Token::getRelevantToken(std::string tokenStrRepresentation) {
	if (tokenStrRepresentation == MULTIPLIY_STR_REPRESENTATION) {
		Token* multOpr = new Operator(Operator::Type::MULTIPLICATION);
		return multOpr;
	}
}