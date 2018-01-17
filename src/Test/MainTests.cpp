// Paul Lancaster
// Unit tests.
#define BOOST_TEST_MODULE Main Tests
#include <boost/test/included/unit_test.hpp>

// Files being tested.
#include "../DataStructures/doubleLinkedList.hpp"
#include "../DataStructures/queue.hpp"
#include "../Tokeniser/tokeniser.hpp"
#include "../Parser/parser.hpp"
#include "../Tokeniser/Token/number.hpp"
#include "../Parser/tokenStreamIterator.hpp"

#include <iostream> // For testing
#include <string>

BOOST_AUTO_TEST_CASE(Always_Passes_Test) {
	// To check that tests are passing correctly.
	int i = 1 + 1;
	BOOST_TEST(i == 2);
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

BOOST_AUTO_TEST_CASE(StateContainer_Add_5_Find_States_Test) {
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

	State *state1Found = s.findStateById(id1);
	State *state2Found = s.findStateById(id2);
	State *state3Found = s.findStateById(id3);
	State *state4Found = s.findStateById(id4);
	State *state5Found = s.findStateById(id5);

	BOOST_TEST(state1Found == state1);
	BOOST_TEST(state2Found == state2);
	BOOST_TEST(state3Found == state3);
	BOOST_TEST(state4Found == state4);
	BOOST_TEST(state5Found == state5);
}

BOOST_AUTO_TEST_CASE(StateContainer_Add_2_FindStates_Test) {
	StateContainer s;
	std::string id1 = "1";
	std::string id2 = "2";

	State* state1 = new State(id1);
	State* state2 = new State(id2);

	s.add(state1);
	s.add(state2);

	std::vector<State*> states = s.findStatesById(id1, id2);

	State* state1Found = states.at(0);
	State* state2Found = states.at(1);

	BOOST_TEST(state1Found == state1);
	BOOST_TEST(state2Found == state2);
}

BOOST_AUTO_TEST_CASE(StateContainer_Add_1_Find2States_Test) {
	StateContainer s;
	std::string id1 = "1";
	std::string id2 = "2";

	State* state1 = new State(id1);

	s.add(state1);

	std::vector<State*> states = s.findStatesById(id1, id2);

	State* state1Found = states.at(0);
	State* state2Found = states.at(1);

	BOOST_TEST(state1Found == state1);
	BOOST_TEST(state2Found == nullptr);
}

BOOST_AUTO_TEST_CASE(StateContainer_Empty_Find_State_Test) {
	StateContainer s;
	std::string id = "state1Id";

	try {
		State* state = s.findStateById(id);
		BOOST_TEST(0);
	}
	catch (State_Not_Found_Exception) {
		BOOST_TEST(1);
	}
}

BOOST_AUTO_TEST_CASE(StateContainer_Add_1_Find_Not_Present_State_Test) {
	StateContainer s;
	std::string id = "state1Id";
	std::string id2 = "state2Id";

	State* state1 = new State(id);
	s.add(state1);

	try {
		State* state = s.findStateById(id2);
		BOOST_TEST(0);
	}
	catch (State_Not_Found_Exception& e) {
		BOOST_TEST(1);
	}
}

BOOST_AUTO_TEST_CASE(Create_State_Test) {
	std::string id = "state1Id";
	State* state1 = new State(id);
	BOOST_TEST(state1->getId() == id);
	BOOST_TEST(state1->isAccepting() == false);
}

BOOST_AUTO_TEST_CASE(Create_Accepting_State_Test) {
	std::string id = "state1Id";
	State* state1 = new State(id);
	state1->setAccepting("OPEN_BRACKET");
	BOOST_TEST(state1->getId() == id);
	BOOST_TEST(state1->isAccepting() == true);
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

BOOST_AUTO_TEST_CASE(Tokeniser_Init_Non_Existant_File_Test) {
	std::string fsaDefPath = "fakeDefThatDoesntExist.fsa";
	Tokeniser tokeniser(fsaDefPath);
	// TODO handle this.
}

BOOST_AUTO_TEST_CASE(Tokeniser_Create_Test) {
	Tokeniser tokeniser;
}

BOOST_AUTO_TEST_CASE(Tokeniser_Parse_Accepting_Transition_Test) {
	Tokeniser tokeniser;
	std::string str = "A,(,B,OPEN_BRACKET";
	tokeniser.parseTransition(str);
	BOOST_TEST(tokeniser.getNumberOfStates() == 2);
}

BOOST_AUTO_TEST_CASE(Tokeniser_Add_Transition_Set_Initial_State_Test) {
	Tokeniser tokeniser;
	std::string initalStateId = "A";
	std::string inputStr = "(";
	std::string finalStateId = "B";
	std::string acceptingStateToken = "OPEN_BRACKET";
	tokeniser.addTransition(initalStateId, inputStr, finalStateId, acceptingStateToken);

	tokeniser.setInitialState(inputStr);
}

BOOST_AUTO_TEST_CASE(Tokeniser_Parse_Not_Accepting_getNumberOfStates_Transition_Test) {
	Tokeniser tokeniser;
	std::string str = "A,#,B,";
	tokeniser.parseTransition(str);
	BOOST_TEST(tokeniser.getNumberOfStates() == 2);
}

BOOST_AUTO_TEST_CASE(Tokeniser_Add_Accepting_Transition_getNumberOfStates_Test) {
	Tokeniser tokeniser;
	std::string initalStateId = "A";
	std::string inputStr = "(";
	std::string finalStateId = "B";
	std::string acceptingStateToken = "OPEN_BRACKET";
	tokeniser.addTransition(initalStateId, inputStr, finalStateId, acceptingStateToken);
	BOOST_TEST(tokeniser.getNumberOfStates() == 2);
}

BOOST_AUTO_TEST_CASE(Tokeniser_Add_Not_Accepting_Transition_Test) {
	Tokeniser tokeniser;
	std::string initalStateId = "A";
	std::string inputStr = "#";
	std::string finalStateId = "B";
	std::string acceptingStateToken = "";
	tokeniser.addTransition(initalStateId, inputStr, finalStateId, acceptingStateToken);
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
	Queue<int> *queue1 = new Queue<int>();
	Queue<int> *queue2 = new Queue<int>();

	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	int e = 5;
	int f = 6;

	queue1->enqueue(a);
	queue1->enqueue(b);
	queue1->enqueue(c);

	queue2->enqueue(d);
	queue2->enqueue(e);
	queue2->enqueue(f);

	queue1->append(queue2);

	BOOST_TEST(queue1->getLength() == 6);
}

BOOST_AUTO_TEST_CASE(Queue_Append_Dequeue_All_Test) {
	Queue<int> *queue1 = new Queue<int>();
	Queue<int> *queue2 = new Queue<int>();

	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	int e = 5;
	int f = 6;

	queue1->enqueue(a);
	queue1->enqueue(b);
	queue1->enqueue(c);

	queue2->enqueue(d);
	queue2->enqueue(e);
	queue2->enqueue(f);

	queue1->append(queue2);

	BOOST_TEST(a == queue1->dequeue());
	BOOST_TEST(b == queue1->dequeue());
	BOOST_TEST(c == queue1->dequeue());
	BOOST_TEST(d == queue1->dequeue());
	BOOST_TEST(e == queue1->dequeue());
	BOOST_TEST(f == queue1->dequeue());
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

BOOST_AUTO_TEST_SUITE(TokenStreamIteratorTests)

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Create_Test) {
	TokenStreamIterator tsi;
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_1_Token_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();

	tsi.queueToken(token1);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_2_Token_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();
	Token* token2 = new Token();

	tsi.queueToken(token1);
	tsi.queueToken(token2);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_hasNext_Empty_Test) {
	TokenStreamIterator tsi;

	BOOST_TEST(tsi.hasNext() == false);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_1_hasNext_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();

	tsi.queueToken(token1);

	BOOST_TEST(tsi.hasNext() == false);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_2_hasNext_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();
	Token* token2 = new Token();

	tsi.queueToken(token1);
	tsi.queueToken(token2);

	BOOST_TEST(tsi.hasNext());
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_hasPrevious_Empty_Test) {
	TokenStreamIterator tsi;
	BOOST_TEST(tsi.hasPrevious() == false);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_1_hasPrevious_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();

	tsi.queueToken(token1);

	BOOST_TEST(tsi.hasPrevious() == false);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_2_hasPrevious_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();
	Token* token2 = new Token();

	tsi.queueToken(token1);
	tsi.queueToken(token2);

	BOOST_TEST(tsi.hasPrevious() == false);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_1_nextToken_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();

	tsi.queueToken(token1);

	try {
		Token* token = tsi.nextToken();
		BOOST_TEST(0);
	}
	catch (No_Token_Found_Exception& e) {
		BOOST_TEST(1);
	}
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_2_nextToken_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();
	Token* token2 = new Token();

	tsi.queueToken(token1);
	tsi.queueToken(token2);

	BOOST_TEST(token2 == tsi.nextToken());
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_2_nextToken_previousToken_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();
	Token* token2 = new Token();

	tsi.queueToken(token1);
	tsi.queueToken(token2);

	BOOST_TEST(token2 == tsi.nextToken());
	BOOST_TEST(token1 == tsi.previousToken());
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_2_nextToken_previousToken_Twice_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();
	Token* token2 = new Token();

	tsi.queueToken(token1);
	tsi.queueToken(token2);

	BOOST_TEST(token2 == tsi.nextToken());
	BOOST_TEST(token1 == tsi.previousToken());

	try {
		Token* token = tsi.previousToken();
		BOOST_TEST(0);
	}
	catch (No_Token_Found_Exception& e) {
		BOOST_TEST(1);
	}

}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Empty_getToken_Test) {
	TokenStreamIterator tsi;
	try {
		Token* token = tsi.getToken();
		BOOST_TEST(0);
	}
	catch (No_Token_Found_Exception& e) {
		BOOST_TEST(1);
	}
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_1_getToken_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();

	tsi.queueToken(token1);

	BOOST_TEST(tsi.getToken() == token1);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_2_getToken_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();
	Token* token2 = new Token();

	tsi.queueToken(token1);
	tsi.queueToken(token2);

	BOOST_TEST(tsi.getToken() == token1);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_2_nextToken_getToken_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();
	Token* token2 = new Token();

	tsi.queueToken(token1);
	tsi.queueToken(token2);

	tsi.nextToken();
	BOOST_TEST(tsi.getToken() == token2);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_2_nextToken_previousToken_getToken_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();
	Token* token2 = new Token();

	tsi.queueToken(token1);
	tsi.queueToken(token2);

	tsi.nextToken();
	tsi.previousToken();

	BOOST_TEST(tsi.getToken() == token1);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Remove_Token_Empty_Test) {
	TokenStreamIterator tsi;
	try {
		tsi.remove();
		BOOST_TEST(0);
	}
	catch (No_Token_Found_Exception& e) {
		BOOST_TEST(1);
	}
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_1_Remove_1_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();

	tsi.queueToken(token1);

	tsi.remove();

	BOOST_TEST(tsi.getPos() == 0);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_2_Remove_1_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();
	Token* token2 = new Token();

	tsi.queueToken(token1);
	tsi.queueToken(token2);

	tsi.remove();

	BOOST_TEST(tsi.getPos() == 1);
	BOOST_TEST(tsi.getToken() == token2);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_3_atEnd_Remove_1_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();
	Token* token2 = new Token();
	Token* token3 = new Token();

	tsi.queueToken(token1);
	tsi.queueToken(token2);
	tsi.queueToken(token3);

	// Move to end
	BOOST_TEST(token2 == tsi.nextToken()); // Move to token2
	BOOST_TEST(token3 == tsi.nextToken()); // Move to token3

	BOOST_TEST(tsi.remove() == 2);
	BOOST_TEST(tsi.getPos() == 2);
	BOOST_TEST(tsi.getToken() == token2);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_3_atStart_Remove_1_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();
	Token* token2 = new Token();
	Token* token3 = new Token();

	tsi.queueToken(token1);
	tsi.queueToken(token2);
	tsi.queueToken(token3);

	// Already at start.

	int startPos = EMPTY_POS + 1;

	BOOST_TEST(tsi.remove() == startPos);
	BOOST_TEST(tsi.getPos() == startPos);
	BOOST_TEST(tsi.getToken() == token2);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_3_inMiddle_Remove_1_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();
	Token* token2 = new Token();
	Token* token3 = new Token();

	tsi.queueToken(token1);
	tsi.queueToken(token2);
	tsi.queueToken(token3);

	// Move to middle
	BOOST_TEST(tsi.nextToken() == token2); // Position 2
	BOOST_TEST(tsi.remove() == 2); // Remove the token which should now mean the stream contains token1->token3 rather than token1->token2->token3.
	BOOST_TEST(tsi.getPos() == 2);
	BOOST_TEST(tsi.getToken() == token3);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_getPos_Empty_Test) {
	TokenStreamIterator tsi;
	BOOST_TEST(tsi.getPos() == 0);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_2_getPos_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();
	Token* token2 = new Token();

	tsi.queueToken(token1);
	tsi.queueToken(token2);

	BOOST_TEST(tsi.getPos() == 1);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_3_atEnd_getPos_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();
	Token* token2 = new Token();
	Token* token3 = new Token();

	tsi.queueToken(token1);
	tsi.queueToken(token2);
	tsi.queueToken(token3);

	// Move to end
	tsi.nextToken(); // Move to token 2
	tsi.nextToken(); // Move to token 3

	BOOST_TEST(tsi.getPos() == 3);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_3_atStart_getPos_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();
	Token* token2 = new Token();
	Token* token3 = new Token();

	tsi.queueToken(token1);
	tsi.queueToken(token2);
	tsi.queueToken(token3);

	BOOST_TEST(tsi.getPos() == EMPTY_POS + 1);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_3_inMiddle_getPos_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();
	Token* token2 = new Token();
	Token* token3 = new Token();

	tsi.queueToken(token1);
	tsi.queueToken(token2);
	tsi.queueToken(token3);

	// Move to middle
	tsi.nextToken();

	BOOST_TEST(tsi.getPos() == EMPTY_POS + 2);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_3_Next_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();
	Token* token2 = new Token();
	Token* token3 = new Token();

	tsi.queueToken(token1);
	tsi.queueToken(token2);
	tsi.queueToken(token3);

	BOOST_TEST(tsi.hasNext());
	BOOST_TEST(tsi.nextToken() == token2);
	BOOST_TEST(tsi.hasNext());
	BOOST_TEST(tsi.nextToken() == token3);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_5_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();
	Token* token2 = new Token();
	Token* token3 = new Token();
	Token* token4 = new Token();
	Token* token5 = new Token();

	tsi.queueToken(token1);
	tsi.queueToken(token2);
	tsi.queueToken(token3);
	tsi.queueToken(token4);
	tsi.queueToken(token5);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_5_getPos_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();
	Token* token2 = new Token();
	Token* token3 = new Token();
	Token* token4 = new Token();
	Token* token5 = new Token();

	tsi.queueToken(token1);
	tsi.queueToken(token2);
	tsi.queueToken(token3);
	tsi.queueToken(token4);
	tsi.queueToken(token5);

	BOOST_TEST(tsi.getPos() == 1);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_5_hasPrevious_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();
	Token* token2 = new Token();
	Token* token3 = new Token();
	Token* token4 = new Token();
	Token* token5 = new Token();

	tsi.queueToken(token1);
	tsi.queueToken(token2);
	tsi.queueToken(token3);
	tsi.queueToken(token4);
	tsi.queueToken(token5);

	BOOST_TEST(tsi.hasPrevious() == false);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_5_hasNext_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();
	Token* token2 = new Token();
	Token* token3 = new Token();
	Token* token4 = new Token();
	Token* token5 = new Token();

	tsi.queueToken(token1);
	tsi.queueToken(token2);
	tsi.queueToken(token3);
	tsi.queueToken(token4);
	tsi.queueToken(token5);

	BOOST_TEST(tsi.hasNext() == true);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_5_getToken_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();
	Token* token2 = new Token();
	Token* token3 = new Token();
	Token* token4 = new Token();
	Token* token5 = new Token();

	tsi.queueToken(token1);
	tsi.queueToken(token2);
	tsi.queueToken(token3);
	tsi.queueToken(token4);
	tsi.queueToken(token5);

	BOOST_TEST(tsi.getToken() == token1);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_5_nextToken_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();
	Token* token2 = new Token();
	Token* token3 = new Token();
	Token* token4 = new Token();
	Token* token5 = new Token();

	tsi.queueToken(token1);
	tsi.queueToken(token2);
	tsi.queueToken(token3);
	tsi.queueToken(token4);
	tsi.queueToken(token5);

	BOOST_TEST(tsi.nextToken() == token2);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_5_nextTokenValue_Test) {
	TokenStreamIterator tsi;

	std::string token1Str = "Token 1";
	std::string token2Str = "Token 2";
	std::string token3Str = "Token 3";
	std::string token4Str = "Token 4";
	std::string token5Str = "Token 5";

	Token* token1 = new Token();
	token1->setValue(token1Str);
	Token* token2 = new Token();
	token2->setValue(token2Str);
	Token* token3 = new Token();
	token3->setValue(token3Str);
	Token* token4 = new Token();
	token4->setValue(token4Str);
	Token* token5 = new Token();
	token5->setValue(token5Str);

	tsi.queueToken(token1);
	tsi.queueToken(token2);
	tsi.queueToken(token3);
	tsi.queueToken(token4);
	tsi.queueToken(token5);

	Token* token = tsi.nextToken();
	BOOST_TEST(token->getValue() == token2Str);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Empty_setPos_Out_Of_Range_Test) {
	TokenStreamIterator tsi;
	BOOST_TEST(tsi.setPos(1) == false);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_1_setPos_Out_Of_Range_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();

	tsi.queueToken(token1);

	BOOST_TEST(tsi.setPos(2) == false);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_2_setPos_2_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();
	Token* token2 = new Token();

	tsi.queueToken(token1);
	tsi.queueToken(token2);

	BOOST_TEST(tsi.setPos(2));
	BOOST_TEST(tsi.getPos() == 2);
	BOOST_TEST(tsi.getToken() == token2);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_3_setPos_Start_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();
	Token* token2 = new Token();
	Token* token3 = new Token();

	tsi.queueToken(token1);
	tsi.queueToken(token2);
	tsi.queueToken(token3);

	BOOST_TEST(tsi.setPos(1));
	BOOST_TEST(tsi.getPos() == 1);
	BOOST_TEST(tsi.getToken() == token1);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_3_setPos_End_Test) {
	TokenStreamIterator tsi;
	Token* token1 = new Token();
	Token* token2 = new Token();
	Token* token3 = new Token();

	tsi.queueToken(token1);
	tsi.queueToken(token2);
	tsi.queueToken(token3);

	BOOST_TEST(tsi.setPos(3));
	BOOST_TEST(tsi.getPos() == 3);
	BOOST_TEST(tsi.getToken() == token3);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_Queue_3_setPos_Middle_Test) {
	TokenStreamIterator tsi;
	Token *token1 = new Token();
	Token *token2 = new Token();
	Token *token3 = new Token();

	tsi.queueToken(token1);
	tsi.queueToken(token2);
	tsi.queueToken(token3);

	BOOST_TEST(tsi.setPos(2));
	BOOST_TEST(tsi.getPos() == 2);
	BOOST_TEST(tsi.getToken() == token2);
}

BOOST_AUTO_TEST_CASE(TokenStreamIterator_setPos_Empty_Test) {
	TokenStreamIterator tsi;
	BOOST_TEST(tsi.setPos(0) == false);
}
BOOST_AUTO_TEST_SUITE_END()
