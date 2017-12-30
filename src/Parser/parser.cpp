#include "parser.hpp"

bool Declaration::recognise(TokenStreamIterator* stream) {
	return DataType.recognise(stream) && Variable.recognise(stream));
}

bool Number::recognise(TokenStreamIterator* stream) {

}