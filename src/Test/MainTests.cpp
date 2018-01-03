// Paul Lancaster
// Unit tests.
#define BOOST_TEST_MODULE Main Tests
#include <boost/test/included/unit_test.hpp>
#include "../RPN/list.hpp"

BOOST_AUTO_TEST_CASE(test_to_make_sure_tests_work) {
	int i = 1 + 1;
	BOOST_TEST(i == 2);
	//BOOST_TEST(i == 1);
}

BOOST_AUTO_TEST_SUITE(QueueTests)

BOOST_AUTO_TEST_CASE(Queue_Create_Test) {
	Queue<int> q;
	BOOST_TEST(q.getLength() == 0);
}

BOOST_AUTO_TEST_SUITE_END()
