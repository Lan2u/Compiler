#include "token.hpp"

class Number : public Token {
public:
	Number(std::string* val);
};

class Integer : public Number {
protected:
public:
	Integer(std::string* val) : Number(val) {};
};
