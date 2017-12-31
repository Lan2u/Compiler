#ifndef Compiler
#define Compiler
#include <string>
#include "Parser\parser.hpp"
#include "Preprocessor\preprocessor.hpp"
#include "Tokeniser\tokeniser.hpp"

class Compiler {
public:
	// Compile the given file.
	void compile(std::string, std::string);
};

#endif