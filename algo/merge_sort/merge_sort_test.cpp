#include "gtest/gtest.h"
#include <deque>
#include "merge_sort.hpp"

namespace {
class MergeTest : public ::testing::Test {
};
TEST_F(MergeTest, eq) {
	std::deque<int> test {2, 6, 8, 4, 1, 3, 5, 0}, check {0, 1, 2, 3, 4, 5, 6, 8};
	ASSERT_EQ(check, merge_sort(test));
}
}
GTEST_API_ int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
