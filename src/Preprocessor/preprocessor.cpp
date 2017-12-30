// preprocessor.cpp
// Eva Lott and Paul Lancaster
// Created	30/12/17
// Edited	30/12/17

#include "preprocessor.hpp"

using namespace std;

Queue<string>* getFileContents (string filename)
{
	Queue<string>* queue = new Queue<string>;
    ifstream file;
	string str;

	// Open file stream
    file.open(filename);
    if (!file.is_open())
		exit(EXIT_FAILURE); // TODO : error system for file not found

	// Loop through words
	while (file >> str)
    {
		// The string is a single character
		if (str.length() == 1)
			queue->push(str);
		
		// The string is multiple characters, which could be multiple operators not seperarated by
		else {
			if (!Postfix::isNumber(str[0]))
		}
    }
	
	

}
