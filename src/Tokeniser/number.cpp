#include "token.hpp"

class Number : public Token {
public:
	Number(std::string* val) : Token(val);
	virtual *string getType() =0;
};

class Integer : public Number {
protected:
	static const std::string type = "INTEGER";
public:
	Integer(string* val) : Number(val) {};
};

*string Integer::getType() {
	return type;
}
