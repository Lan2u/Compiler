// Paul Lancaster
// Unit tests.
#define BOOST_TEST_MODULE Main Tests
#include <boost/test/included/unit_test.hpp>

#include "../DataStructures/doubleLinkedList.hpp"
#include "../DataStructures/queue.hpp"
#include "../Tokeniser/tokeniser.hpp"
#include "../Parser/parser.hpp"
#include "../Tokeniser/Token/number.hpp"

#include <iostream> // For testing
#include <string>

BOOST_AUTO_TEST_CASE(Test_to_make_sure_tests_work) {
	int i = 1 + 1;
	BOOST_TEST(i == 2);
	//BOOST_TEST(i == 1);
}

BOOST_AUTO_TEST_SUITE(StateContainerTests)

BOOST_AUTO_TEST_CASE(StateContainer_Create_Test) {
	StateContainer s;
	BOOST_TEST(s.getLength() == 0);
}

BOOST_AUTO_TEST_CASE(StateContainer_Add_1_State_Test) {
	StateContainer s;
	std::string id = "1";
	State* state = new State(id);
	s.add(state);
	BOOST_TEST(s.getLength() == 1);
}

BOOST_AUTO_TEST_CASE(StateContainers_Add_5_Test) {
	StateContainer s;
	std::string id1 = "1";
	std::string id2 = "2";
	std::string id3 = "3";
	std::string id4 = "4";
	std::string id5 = "5";

	State* state1 = new State(id1);
	State* state2 = new State(id2);
	State* state3 = new State(id3);
	State* state4 = new State(id4);
	State* state5 = new State(id5);

	s.add(state1);
	s.add(state2);
	s.add(state3);
	s.add(state4);
	s.add(state5);
	BOOST_TEST(s.getLength() == 5);
}

BOOST_AUTO_TEST_CASE(StateContainer_Add_5_Find_State_Test) {
	StateContainer s;
	std::string id1 = "1";
	std::string id2 = "2";
	std::string id3 = "3";
	std::string id4 = "4";
	std::string id5 = "5";

	State* state1 = new State(id1);
	State* state2 = new State(id2);
	State* state3 = new State(id3);
	State* state4 = new State(id4);
	State* state5 = new State(id5);

	s.add(state1);
	s.add(state2);
	s.add(state3);
	s.add(state4);
	s.add(state5);
	State *found = s.findStateById(id3);
	BOOST_TEST(found == state3);
}

BOOST_AUTO_TEST_SUITE_END()
 
BOOST_AUTO_TEST_SUITE(ListTests)

BOOST_AUTO_TEST_CASE(List_Create_Test) {
	DoubleLinkedList<int> l;
	BOOST_TEST(l.getLength() == 0);
}

BOOST_AUTO_TEST_CASE(List_Add_Test) {
	DoubleLinkedList<int> l;
	int a = 10;
	l.add(a);
	BOOST_TEST(l.getLength() == 1);
}

BOOST_AUTO_TEST_CASE(List_Add_One_Contains_Test) {
	DoubleLinkedList<int> l;
	int a = 10;
	l.add(a);
	BOOST_TEST(l.contains(a));
}

BOOST_AUTO_TEST_CASE(List_Add_One_No_Contains_Test) {
	DoubleLinkedList<int> l;
	int a = 10;
	int b = 0;

	l.add(a);
	BOOST_TEST(l.contains(b) == false);
}

BOOST_AUTO_TEST_CASE(List_Empty_Contains_Test) {
	DoubleLinkedList<int> l;
	int b = 0;

	BOOST_TEST(l.contains(b) == false);
}

BOOST_AUTO_TEST_CASE(List_Add_One_Remove_One_Test) {
	DoubleLinkedList<int> l;
	int a = 10;
	l.add(a);
	l.remove(a);
	BOOST_TEST(l.getLength() == 0);
}

BOOST_AUTO_TEST_CASE(List_Add_Two_Remove_One_Test) {
	DoubleLinkedList<int> l;
	int a = 10;
	int b = 5;
	l.add(a);
	l.add(b);
	l.remove(a);
	BOOST_TEST(l.getLength() == 1);
}

BOOST_AUTO_TEST_CASE(List_Add_One_Remove_One_Not_Present_Test) {
	DoubleLinkedList<int> l;
	int a = 10;
	int b = 5;
	l.add(a);
	// TODO handle exceptions in test cases
	l.remove(b);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TokeniserTests)

BOOST_AUTO_TEST_CASE(Tokeniser_Tokenise_Int_Test) {
	std::string fsaDefPath = "tokeniserDef.fsa";
	Tokeniser tokeniser(fsaDefPath);

}

BOOST_AUTO_TEST_CASE(Tokeniser_Add_Transition_Test) {
	Tokeniser tokeniser;
	std::string str = "A,(,B,OPEN_BRACKET";
	tokeniser.addTransition(str);
	BOOST_TEST(tokeniser.getNumberOfStates() == 2);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(QueueTests)

BOOST_AUTO_TEST_CASE(Queue_Create_Test) {
	Queue<int> q;
	BOOST_TEST(q.getLength() == 0);
}

BOOST_AUTO_TEST_CASE(Queue_Enqueue_One_Test) {
	Queue<int> q;
	int a = 2;
	q.enqueue(a);
	BOOST_TEST(q.getLength() == 1);
}

BOOST_AUTO_TEST_CASE(Queue_Enqueue_One_Dequeue_One_Test) {
	Queue<int> q;
	int a = 2;
	q.enqueue(a);
	int b = q.dequeue();
	BOOST_TEST(a == b);
	BOOST_TEST(q.getLength() == 0);
}

BOOST_AUTO_TEST_CASE(Queue_Enqueue_Three_Dequeue_All_Test) {
	Queue<int> q;
	int a = 2;
	int b = 3;
	int c = 4;
	q.enqueue(a);
	q.enqueue(b);
	q.enqueue(c);

	BOOST_TEST(q.getLength() == 3);

	BOOST_TEST(a == q.dequeue());
	BOOST_TEST(b == q.dequeue());
	BOOST_TEST(c == q.dequeue());

	BOOST_TEST(q.getLength() == 0);
}

BOOST_AUTO_TEST_CASE(Queue_Append_Test) {
	Queue<int> queue1;
	Queue<int> queue2;

	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	int e = 5;
	int f = 6;

	queue1.enqueue(a);
	queue1.enqueue(b);
	queue1.enqueue(c);

	queue2.enqueue(d);
	queue2.enqueue(e);
	queue2.enqueue(f);

	queue1.append(&queue2);

	BOOST_TEST(queue1.getLength() == 6);

	BOOST_TEST(a == queue1.dequeue());
	BOOST_TEST(b == queue1.dequeue());
	BOOST_TEST(c == queue1.dequeue());
	BOOST_TEST(d == queue1.dequeue());
	BOOST_TEST(e == queue1.dequeue());
	BOOST_TEST(f == queue1.dequeue());
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(RecogniserTests)

BOOST_AUTO_TEST_CASE(Recognise_Number_Positive_Test) {
	TokenStreamIterator* tokenStreamIterator = new TokenStreamIterator();
	Token* number = new Number();
	tokenStreamIterator->queueToken(number);

	Recogniser recogniser;
	BOOST_TEST(recogniser.recogniseNumber(tokenStreamIterator));
	BOOST_TEST(tokenStreamIterator->getPos() == 1); // The token stream iterator should of been advanced 
}

BOOST_AUTO_TEST_CASE(Recognise_Number_Negative_Test) {
	TokenStreamIterator* tokenStreamIterator = new TokenStreamIterator();

	Recogniser recogniser;
	BOOST_TEST(recogniser.recogniseNumber(tokenStreamIterator) == false);
}

BOOST_AUTO_TEST_SUITE_END()
