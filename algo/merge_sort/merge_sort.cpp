#include <iostream>
#include "merge_sort.hpp"

int main() {
	std::deque<int> deq {6, 2, 8, 4, 1, 3, 5, 0};
	deq = merge_sort(deq);
	for(const auto &a : deq) std::cout << a << " ";
	std::cout << std::endl;
	return 0;
}
