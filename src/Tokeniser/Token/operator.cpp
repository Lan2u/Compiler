#include "operator.hpp"

// Create an operator based on the inputted symbol
Operator::Operator(char symbol) : Operator(type)
{
	// Assign precidence and type to the operator
	switch (symbol) {
	case '!':
		type = Type::NEGATION;
		break;
	case '%':
		type = Type::REMAINDER;
		break;
	case '&':
		type = Type::AND;
		break;
	case '*':
		type = Type::MULTIPLICATION;
		break;
	case '+':
		type = Type::ADDITION;
		break;
	case '-':
		type = Type::SUBTRACTION;
		break;
	case '/':
		type = Type::DIVISION;
		break;
	case '<':
		type = Type::COMPARISON;
		break;
	case '=':
		type = Type::EQUALS;
		break;
	case '^':
		type = Type::POWER;
		break;
	case '|':
		type = Type::OR;
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
	// If Operator (char) has been used then type will have already been set,
	// if not then it is set here
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
