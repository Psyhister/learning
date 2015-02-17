#include <iostream>
#include "array_downloader.hpp"
#include "merge_sort.hpp"

int main() {
	std::deque<int> deq;
	fillArray("http://spark-public.s3.amazonaws.com/algo1/programming_prob/IntegerArray.txt", deq);
	deq = merge_sort(deq);
	for(const auto &a : deq)
		std::cout << a << std::endl;
	return 0;
}
