#include "compiler.hpp"

void Compiler::compile(std::string codeFilePath, std::string outPath)
{
	// This is the general layout of the source code -> compiled code sequence.
	/* PSEUDOCODE
	charStream = PREPROCESSOR.LOAD(codeFilePath); // The source code is now broken up into chunks delimited by whitespace characters
	tokenStream = TOKENISER.TOKENISE(charStream); // The chunks are now tokenised into tokens representing what they represented at a very close level (; = SEMICOLON etc. regardless of actual context)
	parseTree = PARSER.PARSE(tokenStream); // The tokens are now added to a parse tree which encapsulates what they actually mean/do in their context. 
	optimisedParseTree = OPTIMISER.OPTIMIZE(parseTree); // Peephole optimisation is now performed on the parsetree/expression tree to minimize code
	compiledCode = COMPILER.COMPILE(optimisedParseTree); // Each node in the parse tree is then compiled using postfix notation into a 1D stream of assembly
	FILE_WRITER.write(compiledCode, outPath); // The assembly is written to a file with sutiable metadata.
	*/
}
