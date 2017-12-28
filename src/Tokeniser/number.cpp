#include "token.hpp"

class Number : public Token {
public:
	Number(string* val) : Token(val);
	virtual *string getType() =0;
};

class Integer : public Number {
protected:
	static string type = "INTEGER";
public:
	Integer(string* val) : Number(val) {};
};

*string Integer::getType() {
	return type;
}
