#include "identifier.hpp"

Identifier::Identifier(std::string val)
{
	value = val;
}

Token::TokenType Identifier::getType()
{
	return TokenType::IDENTIFIER;
}

std::string Identifier::getValue()
{
	return value;
}
