#pragma once
#include <deque>

std::deque<int>  sort_and_count_inversions(const std::deque<int> &arr, long long &inversions) {
	if(arr.size() == 1) {
		return arr;
	}
	std::deque<int> left = sort_and_count_inversions(std::deque<int>(arr.begin(), arr.begin() + arr.size() / 2), inversions);
	std::deque<int> right = sort_and_count_inversions(std::deque<int>(arr.begin() + arr.size() / 2, arr.end()), inversions);
	std::deque<int> result;

	for(size_t i = 0; i < arr.size(); i++) {
		if(right.empty() || !left.empty() && *left.begin() < *right.begin()){
			result.push_back(*left.begin());
			left.pop_front();
		}
		else {
			result.push_back(*right.begin());
			right.pop_front();
			inversions += left.size();
		}
	}
	return result;
}

