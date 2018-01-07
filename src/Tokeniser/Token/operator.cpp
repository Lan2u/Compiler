#include "operator.hpp"

// Create an operator based on the inputted symbol
Operator::Operator(char symbol)
{
	// Assign precidence and type to the operator
	switch (symbol) {
	case '!':
		type = Type::NEGATION;
		precidence = Precidence::NEGATION;
		break;
	case '%':
		type = Type::REMAINDER;
		precidence = Precidence::REMAINDER;
		break;
	case '&':
		type = Type::AND;
		precidence = Precidence::AND;
		break;
	case '*':
		type = Type::MULTIPLICATION;
		precidence = Precidence::MULTIPLICATION;
		break;
	case '+':
		type = Type::ADDITION;
		precidence = Precidence::ADDITION;
		break;
	case '-':
		type = Type::SUBTRACTION;
		precidence = Precidence::SUBTRACTION;
		break;
	case '/':
		type = Type::DIVISION;
		precidence = Precidence::DIVISION;
		break;
	case '<':
		type = Type::COMPARISON;
		precidence = Precidence::COMPARISON;
		break;
	case '=':
		type = Type::EQUALS;
		precidence = Precidence::EQUALS;
		break;
	case '^':
		type = Type::POWER;
		precidence = Precidence::POWER;
		break;
	case '|':
		type = Type::OR;
		precidence = Precidence::OR;
		break;
	default:
		// An invalid operator has been used
		// TODO: Create an error system... If the user accidentally uses x instead of * we could possibly show them where?
		exit(EXIT_FAILURE);
		break;
	}
}

TokenType Operator::getType()
{
	return TokenType::OPERATOR;
}

std::string * Operator::getValue()
{
	return nullptr;
}
