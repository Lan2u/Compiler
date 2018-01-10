#include "operator.hpp"

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
