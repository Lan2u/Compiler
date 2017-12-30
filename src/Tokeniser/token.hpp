#ifndef TOKEN_HPP
#define TOKEN_HPP
// token.hpp
// Paul Lancaster

#include <string>

class Token {
protected:
	std::string *value;
public:
	virtual std::string* getValue() = 0;
};


#endif // TOKEN_HPP
