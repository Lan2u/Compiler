// file_to_queue_test.hpp
// Eva Lott
// Created	30/12/17
// Edited	30/12/17
// Just a little test to see if I can efficiently get a fuction to pull in a file's contents into a Queue of strings accounting for brackets, spaces, tabs, operators etc. I'm thinking it would be easier to tokenise if it's already in a queue.

#include <string>
#include <fstream>

#include "RPN/list.hpp"

class FileIO {
private:
public:
	static Queue<std::string>* getFileContents (std::string);
};