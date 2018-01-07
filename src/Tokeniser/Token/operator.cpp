#include "operator.hpp"
#include "operator.hpp"

// Create an operator based on the inputted symbol
Operator::Operator(char symbol)
{
	// Assign precidence and type to the operator
	switch (symbol) {
	case '!':
		Operator::Operator(Type::NEGATION);
		break;
	case '%':
		Operator::Operator(Type::REMAINDER);
		break;
	case '&':
		Operator::Operator(Type::AND);
		break;
	case '*':
		Operator::Operator(Type::MULTIPLICATION);
		break;
	case '+':
		Operator::Operator(Type::ADDITION);
		break;
	case '-':
		Operator::Operator(Type::SUBTRACTION);
		break;
	case '/':
		Operator::Operator(Type::DIVISION);
		break;
	case '<':
		Operator::Operator(Type::COMPARISON);
		break;
	case '=':
		Operator::Operator(Type::EQUALS);
		break;
	case '^':
		Operator::Operator(Type::POWER);
		break;
	case '|':
		Operator::Operator(Type::OR);
		break;
	default:
		// An invalid operator has been used
		// TODO: Create an error system... If the user accidentally uses x instead of * we could possibly show them where?
		exit(EXIT_FAILURE);
		break;
	}
	value = std::string(1, symbol);
}

Operator::Operator(Type operatorType)
{
	type = operatorType;
	switch (operatorType) {
	case Type::NEGATION:
		precidence = Precidence::NEGATION;
		break;
	case Type::REMAINDER:
		precidence = Precidence::REMAINDER;
		break;
	case Type::AND:
		precidence = Precidence::AND;
		break;
	case Type::MULTIPLICATION:
		precidence = Precidence::MULTIPLICATION;
		break;
	case Type::ADDITION:
		precidence = Precidence::ADDITION;
		break;
	case Type::SUBTRACTION:
		precidence = Precidence::SUBTRACTION;
		break;
	case Type::DIVISION:
		precidence = Precidence::DIVISION;
		break;
	case Type::COMPARISON:
		precidence = Precidence::COMPARISON;
		break;
	case Type::EQUALS:
		precidence = Precidence::EQUALS;
		break;
	case Type::POWER:
		precidence = Precidence::POWER;
		break;
	case Type::OR:
		precidence = Precidence::OR;
		break;
	}
}

Token::TokenType Operator::getType()
{
	return TokenType::OPERATOR;
}

std::string Operator::getValue()
{
	return value;
}
