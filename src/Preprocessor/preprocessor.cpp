// Eva Lott and Paul Lancaster
// Created	30/12/17

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
		queue->enqueue(str);
    }
	
	file.close();
}
