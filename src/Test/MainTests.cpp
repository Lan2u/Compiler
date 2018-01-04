// Paul Lancaster
// Unit tests.
#define BOOST_TEST_MODULE Main Tests
#include <boost/test/included/unit_test.hpp>
#include "../Data Structures/data_structures.hpp"
#include "../Tokeniser/tokeniser.hpp"

BOOST_AUTO_TEST_CASE(test_to_make_sure_tests_work) {
	int i = 1 + 1;
	BOOST_TEST(i == 2);
	//BOOST_TEST(i == 1);
}

BOOST_AUTO_TEST_SUITE(ListTests)

BOOST_AUTO_TEST_CASE(List_Create_Test) {
	List<int> l;
	BOOST_TEST(l.getLength() == 0);
}

BOOST_AUTO_TEST_CASE(List_Push_Test) {
	List<int> l;
	int a = 10;
	l.push(a);
	BOOST_TEST(l.getLength() == 1);
}

BOOST_AUTO_TEST_CASE(List_Push_One_Contains_Test) {
	List<int> l;
	int a = 10;
	l.push(a);
	BOOST_TEST(l.contains(a));
}

BOOST_AUTO_TEST_CASE(List_Push_One_No_Contains_Test) {
	List<int> l;
	int a = 10;
	int b = 0;

	l.push(a);
	BOOST_TEST(l.contains(b) == false);
}

BOOST_AUTO_TEST_CASE(List_Empty_Contains_Test) {
	List<int> l;
	int b = 0;

	BOOST_TEST(l.contains(b) == false);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TokeniserTests)

BOOST_AUTO_TEST_CASE(Tokeniser_Tokenise_Int_Test) {
	std::string fsaDefPath = "tokeniserDef.fsa";
	Tokeniser tokeniser(fsaDefPath);

}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(QueueTests)

BOOST_AUTO_TEST_CASE(Queue_Create_Test) {
	Queue<int> q;
	BOOST_TEST(q.getLength() == 0);
}

BOOST_AUTO_TEST_CASE(Queue_Add_One_Test) {
	Queue<int> q;
	int a = 2;
	q.push(a);
	BOOST_TEST(q.getLength() == 1);
}

BOOST_AUTO_TEST_CASE(Queue_Add_One_Remove_One_Test) {
	Queue<int> q;
	int a = 2;
	q.push(a);
	int b = q.pop();
	BOOST_TEST(a == b);
	BOOST_TEST(q.getLength() == 0);
}

BOOST_AUTO_TEST_CASE(Queue_Add_Three_Remove_All_Test) {
	Queue<int> q;
	int a = 2;
	int b = 3;
	int c = 4;
	q.push(a);
	q.push(b);
	q.push(c);

	BOOST_TEST(q.getLength() == 3);

	BOOST_TEST(a == q.pop());
	BOOST_TEST(b == q.pop());
	BOOST_TEST(c == q.pop());

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

	queue1.push(a);
	queue1.push(b);
	queue1.push(c);

	queue2.push(d);
	queue2.push(e);
	queue2.push(f);

	queue1.append(&queue2);

	BOOST_TEST(queue1.getLength() == 6);

	BOOST_TEST(a == queue1.pop());
	BOOST_TEST(b == queue1.pop());
	BOOST_TEST(c == queue1.pop());
	BOOST_TEST(d == queue1.pop());
	BOOST_TEST(e == queue1.pop());
	BOOST_TEST(f == queue1.pop());
}

BOOST_AUTO_TEST_SUITE_END()
