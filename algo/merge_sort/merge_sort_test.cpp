#include "gtest/gtest.h"
#include <deque>
#include <algorithm>
#include <random>
#include <chrono>
#include "merge_sort.hpp"
#include "array_downloader.hpp"

namespace {
class MergeTest : public ::testing::Test {
};
TEST_F(MergeTest, eq) {
	std::deque<int> test {2, 6, 8, 4, 1, 3, 5, 0};
	test = merge_sort(test);
	ASSERT_TRUE(std::is_sorted(test.begin(), test.end()));
}
TEST_F(MergeTest, eqBig) {
	std::deque<int> test;
	::fillArray("http://spark-public.s3.amazonaws.com/algo1/programming_prob/IntegerArray.txt", test);
	test = merge_sort(test);
	ASSERT_TRUE(std::is_sorted(test.begin(), test.end()));
}
TEST_F(MergeTest, eqRand) {
	std::deque<int> test;
	std::default_random_engine rd(std::chrono::system_clock::now().time_since_epoch().count());
	for (int i = 0; i < 10000; i++) {
		test.push_back(rd());
	}
	test = merge_sort(test);
	ASSERT_TRUE(std::is_sorted(test.begin(), test.end()));
}
}
GTEST_API_ int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
