#pragma once
#include <deque>

std::deque<int>  merge_sort(const std::deque<int> &arr) {
	if(arr.size() == 1)
		return arr;
	std::deque<int> left = merge_sort(std::deque<int>(arr.begin(), arr.begin() + arr.size() / 2));
	std::deque<int> right = merge_sort(std::deque<int>(arr.begin() + arr.size() / 2, arr.end()));
	std::deque<int> result;

	for(size_t i = 0; i < arr.size(); i++) {
		if(right.empty() || !left.empty() && *left.begin() < *right.begin()){
			result.push_back(*left.begin());
			left.pop_front();
		}
		else {
			result.push_back(*right.begin());
			right.pop_front();
		}
	}
	return result;
}

