// file_to_queue_test.cpp
// Eva Lott
// Created	30/12/17
// Edited	30/12/17

#include "file_to_queue_test.hpp"

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
		
		else {
			if (!RPN::isNumber(str[0]))
		}
    }
	
	

}
