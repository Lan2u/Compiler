// Paul Lancaster
// Created to test the unit test library.
#define BOOST_TEST_MODULE My Test
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(first_test) {
	int i = 1 + 1;
	BOOST_TEST(i == 2);
	//BOOST_TEST(i == 1);
}