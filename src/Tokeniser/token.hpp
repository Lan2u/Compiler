#ifndef TOKEN_HPP
#define TOKEN_HPP
// token.hpp
// Paul Lancaster

#include <string>

class Token {
protected:
	std::string *value;
public:
	virtual *string getType() = 0;
};

#endif // TOKEN_HPP
