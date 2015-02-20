#include <iostream>
#include "array_downloader.hpp"
#include "inversions.hpp"

int main() {
	std::deque<int> deq;
	fillArray("http://spark-public.s3.amazonaws.com/algo1/programming_prob/IntegerArray.txt", deq);
	long long inversions = 0;
	deq = sort_and_count_inversions(deq, inversions);
	/*for(const auto &a : deq)
		std::cout << a << std::endl;*/
	std::cout << inversions << std::endl;
	return 0;
}
