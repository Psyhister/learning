#include <iostream>
#include "inversions.hpp"

int main() {
	std::deque<int> deq {6, 5, 4, 3, 2, 1};
	long long inversions = 0;
	deq = sort_and_count_inversions(deq, inversions);
	for(const auto &a : deq) std::cout << a << " ";
	std::cout << std::endl;
	std::cout << inversions << std::endl;
	return 0;
}
