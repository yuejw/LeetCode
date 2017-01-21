// 491. Increasing Subsequences
// https://leetcode.com/problems/increasing-subsequences/
#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;
class Solution {
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		set<vector<int>> result;
		vector<int> solution;
		findSubsequences(0, solution, nums, result);
		return vector<vector<int>>(begin(result), end(result));
	}
private:
	void findSubsequences(const size_t i, vector<int>& solution, const vector<int>& nums, set<vector<int>>& result) {
		if (i == nums.size()) {
			if (solution.size() > 1) {
				result.insert(solution);
			}
			return;
		}
		size_t j = i + 1;
		while (j < nums.size() && nums[j - 1] == nums[j]) {
			j++;
		}
		findSubsequences(j, solution, nums, result);
		for (size_t k = i; k < j && (solution.empty() || solution.back() <= nums[i]); k++) {
			for (size_t l = 0; l < 1 + k - i; l++) {
				solution.push_back(nums[i]);
			}
			findSubsequences(j, solution, nums, result);
			for (size_t l = 0; l < 1 + k - i; l++) {
				solution.pop_back();
			}
		}
	}
};
int main(void) {
	Solution solution;
	vector<int> nums;
	vector<vector<int>> result;

	nums = {4, 6, 7, 7};
	result = solution.findSubsequences(nums);
	sort(begin(result), end(result));
	assert(vector<vector<int>>({{4, 6}, {4, 6, 7}, {4, 6, 7, 7}, {4, 7}, {4, 7, 7}, {6, 7}, {6, 7, 7}, {7, 7}}) == result);

	nums = {4, 3, 2, 1};
	result = solution.findSubsequences(nums);
	sort(begin(result), end(result));
	assert(vector<vector<int>>({}) == result);

	nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 1, 1, 1, 1};
	result = solution.findSubsequences(nums);
	sort(begin(result), end(result));
	assert(vector<vector<int>>({{1, 1}, {1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}, {1, 2}, {1, 2, 3}, {1, 2, 3, 4}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5, 6}, {1, 2, 3, 4, 5, 6, 7}, {1, 2, 3, 4, 5, 6, 7, 8}, {1, 2, 3, 4, 5, 6, 7, 8, 9}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, {1, 2, 3, 4, 5, 6, 7, 8, 10}, {1, 2, 3, 4, 5, 6, 7, 9}, {1, 2, 3, 4, 5, 6, 7, 9, 10}, {1, 2, 3, 4, 5, 6, 7, 10}, {1, 2, 3, 4, 5, 6, 8}, {1, 2, 3, 4, 5, 6, 8, 9}, {1, 2, 3, 4, 5, 6, 8, 9, 10}, {1, 2, 3, 4, 5, 6, 8, 10}, {1, 2, 3, 4, 5, 6, 9}, {1, 2, 3, 4, 5, 6, 9, 10}, {1, 2, 3, 4, 5, 6, 10}, {1, 2, 3, 4, 5, 7}, {1, 2, 3, 4, 5, 7, 8}, {1, 2, 3, 4, 5, 7, 8, 9}, {1, 2, 3, 4, 5, 7, 8, 9, 10}, {1, 2, 3, 4, 5, 7, 8, 10}, {1, 2, 3, 4, 5, 7, 9}, {1, 2, 3, 4, 5, 7, 9, 10}, {1, 2, 3, 4, 5, 7, 10}, {1, 2, 3, 4, 5, 8}, {1, 2, 3, 4, 5, 8, 9}, {1, 2, 3, 4, 5, 8, 9, 10}, {1, 2, 3, 4, 5, 8, 10}, {1, 2, 3, 4, 5, 9}, {1, 2, 3, 4, 5, 9, 10}, {1, 2, 3, 4, 5, 10}, {1, 2, 3, 4, 6}, {1, 2, 3, 4, 6, 7}, {1, 2, 3, 4, 6, 7, 8}, {1, 2, 3, 4, 6, 7, 8, 9}, {1, 2, 3, 4, 6, 7, 8, 9, 10}, {1, 2, 3, 4, 6, 7, 8, 10}, {1, 2, 3, 4, 6, 7, 9}, {1, 2, 3, 4, 6, 7, 9, 10}, {1, 2, 3, 4, 6, 7, 10}, {1, 2, 3, 4, 6, 8}, {1, 2, 3, 4, 6, 8, 9}, {1, 2, 3, 4, 6, 8, 9, 10}, {1, 2, 3, 4, 6, 8, 10}, {1, 2, 3, 4, 6, 9}, {1, 2, 3, 4, 6, 9, 10}, {1, 2, 3, 4, 6, 10}, {1, 2, 3, 4, 7}, {1, 2, 3, 4, 7, 8}, {1, 2, 3, 4, 7, 8, 9}, {1, 2, 3, 4, 7, 8, 9, 10}, {1, 2, 3, 4, 7, 8, 10}, {1, 2, 3, 4, 7, 9}, {1, 2, 3, 4, 7, 9, 10}, {1, 2, 3, 4, 7, 10}, {1, 2, 3, 4, 8}, {1, 2, 3, 4, 8, 9}, {1, 2, 3, 4, 8, 9, 10}, {1, 2, 3, 4, 8, 10}, {1, 2, 3, 4, 9}, {1, 2, 3, 4, 9, 10}, {1, 2, 3, 4, 10}, {1, 2, 3, 5}, {1, 2, 3, 5, 6}, {1, 2, 3, 5, 6, 7}, {1, 2, 3, 5, 6, 7, 8}, {1, 2, 3, 5, 6, 7, 8, 9}, {1, 2, 3, 5, 6, 7, 8, 9, 10}, {1, 2, 3, 5, 6, 7, 8, 10}, {1, 2, 3, 5, 6, 7, 9}, {1, 2, 3, 5, 6, 7, 9, 10}, {1, 2, 3, 5, 6, 7, 10}, {1, 2, 3, 5, 6, 8}, {1, 2, 3, 5, 6, 8, 9}, {1, 2, 3, 5, 6, 8, 9, 10}, {1, 2, 3, 5, 6, 8, 10}, {1, 2, 3, 5, 6, 9}, {1, 2, 3, 5, 6, 9, 10}, {1, 2, 3, 5, 6, 10}, {1, 2, 3, 5, 7}, {1, 2, 3, 5, 7, 8}, {1, 2, 3, 5, 7, 8, 9}, {1, 2, 3, 5, 7, 8, 9, 10}, {1, 2, 3, 5, 7, 8, 10}, {1, 2, 3, 5, 7, 9}, {1, 2, 3, 5, 7, 9, 10}, {1, 2, 3, 5, 7, 10}, {1, 2, 3, 5, 8}, {1, 2, 3, 5, 8, 9}, {1, 2, 3, 5, 8, 9, 10}, {1, 2, 3, 5, 8, 10}, {1, 2, 3, 5, 9}, {1, 2, 3, 5, 9, 10}, {1, 2, 3, 5, 10}, {1, 2, 3, 6}, {1, 2, 3, 6, 7}, {1, 2, 3, 6, 7, 8}, {1, 2, 3, 6, 7, 8, 9}, {1, 2, 3, 6, 7, 8, 9, 10}, {1, 2, 3, 6, 7, 8, 10}, {1, 2, 3, 6, 7, 9}, {1, 2, 3, 6, 7, 9, 10}, {1, 2, 3, 6, 7, 10}, {1, 2, 3, 6, 8}, {1, 2, 3, 6, 8, 9}, {1, 2, 3, 6, 8, 9, 10}, {1, 2, 3, 6, 8, 10}, {1, 2, 3, 6, 9}, {1, 2, 3, 6, 9, 10}, {1, 2, 3, 6, 10}, {1, 2, 3, 7}, {1, 2, 3, 7, 8}, {1, 2, 3, 7, 8, 9}, {1, 2, 3, 7, 8, 9, 10}, {1, 2, 3, 7, 8, 10}, {1, 2, 3, 7, 9}, {1, 2, 3, 7, 9, 10}, {1, 2, 3, 7, 10}, {1, 2, 3, 8}, {1, 2, 3, 8, 9}, {1, 2, 3, 8, 9, 10}, {1, 2, 3, 8, 10}, {1, 2, 3, 9}, {1, 2, 3, 9, 10}, {1, 2, 3, 10}, {1, 2, 4}, {1, 2, 4, 5}, {1, 2, 4, 5, 6}, {1, 2, 4, 5, 6, 7}, {1, 2, 4, 5, 6, 7, 8}, {1, 2, 4, 5, 6, 7, 8, 9}, {1, 2, 4, 5, 6, 7, 8, 9, 10}, {1, 2, 4, 5, 6, 7, 8, 10}, {1, 2, 4, 5, 6, 7, 9}, {1, 2, 4, 5, 6, 7, 9, 10}, {1, 2, 4, 5, 6, 7, 10}, {1, 2, 4, 5, 6, 8}, {1, 2, 4, 5, 6, 8, 9}, {1, 2, 4, 5, 6, 8, 9, 10}, {1, 2, 4, 5, 6, 8, 10}, {1, 2, 4, 5, 6, 9}, {1, 2, 4, 5, 6, 9, 10}, {1, 2, 4, 5, 6, 10}, {1, 2, 4, 5, 7}, {1, 2, 4, 5, 7, 8}, {1, 2, 4, 5, 7, 8, 9}, {1, 2, 4, 5, 7, 8, 9, 10}, {1, 2, 4, 5, 7, 8, 10}, {1, 2, 4, 5, 7, 9}, {1, 2, 4, 5, 7, 9, 10}, {1, 2, 4, 5, 7, 10}, {1, 2, 4, 5, 8}, {1, 2, 4, 5, 8, 9}, {1, 2, 4, 5, 8, 9, 10}, {1, 2, 4, 5, 8, 10}, {1, 2, 4, 5, 9}, {1, 2, 4, 5, 9, 10}, {1, 2, 4, 5, 10}, {1, 2, 4, 6}, {1, 2, 4, 6, 7}, {1, 2, 4, 6, 7, 8}, {1, 2, 4, 6, 7, 8, 9}, {1, 2, 4, 6, 7, 8, 9, 10}, {1, 2, 4, 6, 7, 8, 10}, {1, 2, 4, 6, 7, 9}, {1, 2, 4, 6, 7, 9, 10}, {1, 2, 4, 6, 7, 10}, {1, 2, 4, 6, 8}, {1, 2, 4, 6, 8, 9}, {1, 2, 4, 6, 8, 9, 10}, {1, 2, 4, 6, 8, 10}, {1, 2, 4, 6, 9}, {1, 2, 4, 6, 9, 10}, {1, 2, 4, 6, 10}, {1, 2, 4, 7}, {1, 2, 4, 7, 8}, {1, 2, 4, 7, 8, 9}, {1, 2, 4, 7, 8, 9, 10}, {1, 2, 4, 7, 8, 10}, {1, 2, 4, 7, 9}, {1, 2, 4, 7, 9, 10}, {1, 2, 4, 7, 10}, {1, 2, 4, 8}, {1, 2, 4, 8, 9}, {1, 2, 4, 8, 9, 10}, {1, 2, 4, 8, 10}, {1, 2, 4, 9}, {1, 2, 4, 9, 10}, {1, 2, 4, 10}, {1, 2, 5}, {1, 2, 5, 6}, {1, 2, 5, 6, 7}, {1, 2, 5, 6, 7, 8}, {1, 2, 5, 6, 7, 8, 9}, {1, 2, 5, 6, 7, 8, 9, 10}, {1, 2, 5, 6, 7, 8, 10}, {1, 2, 5, 6, 7, 9}, {1, 2, 5, 6, 7, 9, 10}, {1, 2, 5, 6, 7, 10}, {1, 2, 5, 6, 8}, {1, 2, 5, 6, 8, 9}, {1, 2, 5, 6, 8, 9, 10}, {1, 2, 5, 6, 8, 10}, {1, 2, 5, 6, 9}, {1, 2, 5, 6, 9, 10}, {1, 2, 5, 6, 10}, {1, 2, 5, 7}, {1, 2, 5, 7, 8}, {1, 2, 5, 7, 8, 9}, {1, 2, 5, 7, 8, 9, 10}, {1, 2, 5, 7, 8, 10}, {1, 2, 5, 7, 9}, {1, 2, 5, 7, 9, 10}, {1, 2, 5, 7, 10}, {1, 2, 5, 8}, {1, 2, 5, 8, 9}, {1, 2, 5, 8, 9, 10}, {1, 2, 5, 8, 10}, {1, 2, 5, 9}, {1, 2, 5, 9, 10}, {1, 2, 5, 10}, {1, 2, 6}, {1, 2, 6, 7}, {1, 2, 6, 7, 8}, {1, 2, 6, 7, 8, 9}, {1, 2, 6, 7, 8, 9, 10}, {1, 2, 6, 7, 8, 10}, {1, 2, 6, 7, 9}, {1, 2, 6, 7, 9, 10}, {1, 2, 6, 7, 10}, {1, 2, 6, 8}, {1, 2, 6, 8, 9}, {1, 2, 6, 8, 9, 10}, {1, 2, 6, 8, 10}, {1, 2, 6, 9}, {1, 2, 6, 9, 10}, {1, 2, 6, 10}, {1, 2, 7}, {1, 2, 7, 8}, {1, 2, 7, 8, 9}, {1, 2, 7, 8, 9, 10}, {1, 2, 7, 8, 10}, {1, 2, 7, 9}, {1, 2, 7, 9, 10}, {1, 2, 7, 10}, {1, 2, 8}, {1, 2, 8, 9}, {1, 2, 8, 9, 10}, {1, 2, 8, 10}, {1, 2, 9}, {1, 2, 9, 10}, {1, 2, 10}, {1, 3}, {1, 3, 4}, {1, 3, 4, 5}, {1, 3, 4, 5, 6}, {1, 3, 4, 5, 6, 7}, {1, 3, 4, 5, 6, 7, 8}, {1, 3, 4, 5, 6, 7, 8, 9}, {1, 3, 4, 5, 6, 7, 8, 9, 10}, {1, 3, 4, 5, 6, 7, 8, 10}, {1, 3, 4, 5, 6, 7, 9}, {1, 3, 4, 5, 6, 7, 9, 10}, {1, 3, 4, 5, 6, 7, 10}, {1, 3, 4, 5, 6, 8}, {1, 3, 4, 5, 6, 8, 9}, {1, 3, 4, 5, 6, 8, 9, 10}, {1, 3, 4, 5, 6, 8, 10}, {1, 3, 4, 5, 6, 9}, {1, 3, 4, 5, 6, 9, 10}, {1, 3, 4, 5, 6, 10}, {1, 3, 4, 5, 7}, {1, 3, 4, 5, 7, 8}, {1, 3, 4, 5, 7, 8, 9}, {1, 3, 4, 5, 7, 8, 9, 10}, {1, 3, 4, 5, 7, 8, 10}, {1, 3, 4, 5, 7, 9}, {1, 3, 4, 5, 7, 9, 10}, {1, 3, 4, 5, 7, 10}, {1, 3, 4, 5, 8}, {1, 3, 4, 5, 8, 9}, {1, 3, 4, 5, 8, 9, 10}, {1, 3, 4, 5, 8, 10}, {1, 3, 4, 5, 9}, {1, 3, 4, 5, 9, 10}, {1, 3, 4, 5, 10}, {1, 3, 4, 6}, {1, 3, 4, 6, 7}, {1, 3, 4, 6, 7, 8}, {1, 3, 4, 6, 7, 8, 9}, {1, 3, 4, 6, 7, 8, 9, 10}, {1, 3, 4, 6, 7, 8, 10}, {1, 3, 4, 6, 7, 9}, {1, 3, 4, 6, 7, 9, 10}, {1, 3, 4, 6, 7, 10}, {1, 3, 4, 6, 8}, {1, 3, 4, 6, 8, 9}, {1, 3, 4, 6, 8, 9, 10}, {1, 3, 4, 6, 8, 10}, {1, 3, 4, 6, 9}, {1, 3, 4, 6, 9, 10}, {1, 3, 4, 6, 10}, {1, 3, 4, 7}, {1, 3, 4, 7, 8}, {1, 3, 4, 7, 8, 9}, {1, 3, 4, 7, 8, 9, 10}, {1, 3, 4, 7, 8, 10}, {1, 3, 4, 7, 9}, {1, 3, 4, 7, 9, 10}, {1, 3, 4, 7, 10}, {1, 3, 4, 8}, {1, 3, 4, 8, 9}, {1, 3, 4, 8, 9, 10}, {1, 3, 4, 8, 10}, {1, 3, 4, 9}, {1, 3, 4, 9, 10}, {1, 3, 4, 10}, {1, 3, 5}, {1, 3, 5, 6}, {1, 3, 5, 6, 7}, {1, 3, 5, 6, 7, 8}, {1, 3, 5, 6, 7, 8, 9}, {1, 3, 5, 6, 7, 8, 9, 10}, {1, 3, 5, 6, 7, 8, 10}, {1, 3, 5, 6, 7, 9}, {1, 3, 5, 6, 7, 9, 10}, {1, 3, 5, 6, 7, 10}, {1, 3, 5, 6, 8}, {1, 3, 5, 6, 8, 9}, {1, 3, 5, 6, 8, 9, 10}, {1, 3, 5, 6, 8, 10}, {1, 3, 5, 6, 9}, {1, 3, 5, 6, 9, 10}, {1, 3, 5, 6, 10}, {1, 3, 5, 7}, {1, 3, 5, 7, 8}, {1, 3, 5, 7, 8, 9}, {1, 3, 5, 7, 8, 9, 10}, {1, 3, 5, 7, 8, 10}, {1, 3, 5, 7, 9}, {1, 3, 5, 7, 9, 10}, {1, 3, 5, 7, 10}, {1, 3, 5, 8}, {1, 3, 5, 8, 9}, {1, 3, 5, 8, 9, 10}, {1, 3, 5, 8, 10}, {1, 3, 5, 9}, {1, 3, 5, 9, 10}, {1, 3, 5, 10}, {1, 3, 6}, {1, 3, 6, 7}, {1, 3, 6, 7, 8}, {1, 3, 6, 7, 8, 9}, {1, 3, 6, 7, 8, 9, 10}, {1, 3, 6, 7, 8, 10}, {1, 3, 6, 7, 9}, {1, 3, 6, 7, 9, 10}, {1, 3, 6, 7, 10}, {1, 3, 6, 8}, {1, 3, 6, 8, 9}, {1, 3, 6, 8, 9, 10}, {1, 3, 6, 8, 10}, {1, 3, 6, 9}, {1, 3, 6, 9, 10}, {1, 3, 6, 10}, {1, 3, 7}, {1, 3, 7, 8}, {1, 3, 7, 8, 9}, {1, 3, 7, 8, 9, 10}, {1, 3, 7, 8, 10}, {1, 3, 7, 9}, {1, 3, 7, 9, 10}, {1, 3, 7, 10}, {1, 3, 8}, {1, 3, 8, 9}, {1, 3, 8, 9, 10}, {1, 3, 8, 10}, {1, 3, 9}, {1, 3, 9, 10}, {1, 3, 10}, {1, 4}, {1, 4, 5}, {1, 4, 5, 6}, {1, 4, 5, 6, 7}, {1, 4, 5, 6, 7, 8}, {1, 4, 5, 6, 7, 8, 9}, {1, 4, 5, 6, 7, 8, 9, 10}, {1, 4, 5, 6, 7, 8, 10}, {1, 4, 5, 6, 7, 9}, {1, 4, 5, 6, 7, 9, 10}, {1, 4, 5, 6, 7, 10}, {1, 4, 5, 6, 8}, {1, 4, 5, 6, 8, 9}, {1, 4, 5, 6, 8, 9, 10}, {1, 4, 5, 6, 8, 10}, {1, 4, 5, 6, 9}, {1, 4, 5, 6, 9, 10}, {1, 4, 5, 6, 10}, {1, 4, 5, 7}, {1, 4, 5, 7, 8}, {1, 4, 5, 7, 8, 9}, {1, 4, 5, 7, 8, 9, 10}, {1, 4, 5, 7, 8, 10}, {1, 4, 5, 7, 9}, {1, 4, 5, 7, 9, 10}, {1, 4, 5, 7, 10}, {1, 4, 5, 8}, {1, 4, 5, 8, 9}, {1, 4, 5, 8, 9, 10}, {1, 4, 5, 8, 10}, {1, 4, 5, 9}, {1, 4, 5, 9, 10}, {1, 4, 5, 10}, {1, 4, 6}, {1, 4, 6, 7}, {1, 4, 6, 7, 8}, {1, 4, 6, 7, 8, 9}, {1, 4, 6, 7, 8, 9, 10}, {1, 4, 6, 7, 8, 10}, {1, 4, 6, 7, 9}, {1, 4, 6, 7, 9, 10}, {1, 4, 6, 7, 10}, {1, 4, 6, 8}, {1, 4, 6, 8, 9}, {1, 4, 6, 8, 9, 10}, {1, 4, 6, 8, 10}, {1, 4, 6, 9}, {1, 4, 6, 9, 10}, {1, 4, 6, 10}, {1, 4, 7}, {1, 4, 7, 8}, {1, 4, 7, 8, 9}, {1, 4, 7, 8, 9, 10}, {1, 4, 7, 8, 10}, {1, 4, 7, 9}, {1, 4, 7, 9, 10}, {1, 4, 7, 10}, {1, 4, 8}, {1, 4, 8, 9}, {1, 4, 8, 9, 10}, {1, 4, 8, 10}, {1, 4, 9}, {1, 4, 9, 10}, {1, 4, 10}, {1, 5}, {1, 5, 6}, {1, 5, 6, 7}, {1, 5, 6, 7, 8}, {1, 5, 6, 7, 8, 9}, {1, 5, 6, 7, 8, 9, 10}, {1, 5, 6, 7, 8, 10}, {1, 5, 6, 7, 9}, {1, 5, 6, 7, 9, 10}, {1, 5, 6, 7, 10}, {1, 5, 6, 8}, {1, 5, 6, 8, 9}, {1, 5, 6, 8, 9, 10}, {1, 5, 6, 8, 10}, {1, 5, 6, 9}, {1, 5, 6, 9, 10}, {1, 5, 6, 10}, {1, 5, 7}, {1, 5, 7, 8}, {1, 5, 7, 8, 9}, {1, 5, 7, 8, 9, 10}, {1, 5, 7, 8, 10}, {1, 5, 7, 9}, {1, 5, 7, 9, 10}, {1, 5, 7, 10}, {1, 5, 8}, {1, 5, 8, 9}, {1, 5, 8, 9, 10}, {1, 5, 8, 10}, {1, 5, 9}, {1, 5, 9, 10}, {1, 5, 10}, {1, 6}, {1, 6, 7}, {1, 6, 7, 8}, {1, 6, 7, 8, 9}, {1, 6, 7, 8, 9, 10}, {1, 6, 7, 8, 10}, {1, 6, 7, 9}, {1, 6, 7, 9, 10}, {1, 6, 7, 10}, {1, 6, 8}, {1, 6, 8, 9}, {1, 6, 8, 9, 10}, {1, 6, 8, 10}, {1, 6, 9}, {1, 6, 9, 10}, {1, 6, 10}, {1, 7}, {1, 7, 8}, {1, 7, 8, 9}, {1, 7, 8, 9, 10}, {1, 7, 8, 10}, {1, 7, 9}, {1, 7, 9, 10}, {1, 7, 10}, {1, 8}, {1, 8, 9}, {1, 8, 9, 10}, {1, 8, 10}, {1, 9}, {1, 9, 10}, {1, 10}, {2, 3}, {2, 3, 4}, {2, 3, 4, 5}, {2, 3, 4, 5, 6}, {2, 3, 4, 5, 6, 7}, {2, 3, 4, 5, 6, 7, 8}, {2, 3, 4, 5, 6, 7, 8, 9}, {2, 3, 4, 5, 6, 7, 8, 9, 10}, {2, 3, 4, 5, 6, 7, 8, 10}, {2, 3, 4, 5, 6, 7, 9}, {2, 3, 4, 5, 6, 7, 9, 10}, {2, 3, 4, 5, 6, 7, 10}, {2, 3, 4, 5, 6, 8}, {2, 3, 4, 5, 6, 8, 9}, {2, 3, 4, 5, 6, 8, 9, 10}, {2, 3, 4, 5, 6, 8, 10}, {2, 3, 4, 5, 6, 9}, {2, 3, 4, 5, 6, 9, 10}, {2, 3, 4, 5, 6, 10}, {2, 3, 4, 5, 7}, {2, 3, 4, 5, 7, 8}, {2, 3, 4, 5, 7, 8, 9}, {2, 3, 4, 5, 7, 8, 9, 10}, {2, 3, 4, 5, 7, 8, 10}, {2, 3, 4, 5, 7, 9}, {2, 3, 4, 5, 7, 9, 10}, {2, 3, 4, 5, 7, 10}, {2, 3, 4, 5, 8}, {2, 3, 4, 5, 8, 9}, {2, 3, 4, 5, 8, 9, 10}, {2, 3, 4, 5, 8, 10}, {2, 3, 4, 5, 9}, {2, 3, 4, 5, 9, 10}, {2, 3, 4, 5, 10}, {2, 3, 4, 6}, {2, 3, 4, 6, 7}, {2, 3, 4, 6, 7, 8}, {2, 3, 4, 6, 7, 8, 9}, {2, 3, 4, 6, 7, 8, 9, 10}, {2, 3, 4, 6, 7, 8, 10}, {2, 3, 4, 6, 7, 9}, {2, 3, 4, 6, 7, 9, 10}, {2, 3, 4, 6, 7, 10}, {2, 3, 4, 6, 8}, {2, 3, 4, 6, 8, 9}, {2, 3, 4, 6, 8, 9, 10}, {2, 3, 4, 6, 8, 10}, {2, 3, 4, 6, 9}, {2, 3, 4, 6, 9, 10}, {2, 3, 4, 6, 10}, {2, 3, 4, 7}, {2, 3, 4, 7, 8}, {2, 3, 4, 7, 8, 9}, {2, 3, 4, 7, 8, 9, 10}, {2, 3, 4, 7, 8, 10}, {2, 3, 4, 7, 9}, {2, 3, 4, 7, 9, 10}, {2, 3, 4, 7, 10}, {2, 3, 4, 8}, {2, 3, 4, 8, 9}, {2, 3, 4, 8, 9, 10}, {2, 3, 4, 8, 10}, {2, 3, 4, 9}, {2, 3, 4, 9, 10}, {2, 3, 4, 10}, {2, 3, 5}, {2, 3, 5, 6}, {2, 3, 5, 6, 7}, {2, 3, 5, 6, 7, 8}, {2, 3, 5, 6, 7, 8, 9}, {2, 3, 5, 6, 7, 8, 9, 10}, {2, 3, 5, 6, 7, 8, 10}, {2, 3, 5, 6, 7, 9}, {2, 3, 5, 6, 7, 9, 10}, {2, 3, 5, 6, 7, 10}, {2, 3, 5, 6, 8}, {2, 3, 5, 6, 8, 9}, {2, 3, 5, 6, 8, 9, 10}, {2, 3, 5, 6, 8, 10}, {2, 3, 5, 6, 9}, {2, 3, 5, 6, 9, 10}, {2, 3, 5, 6, 10}, {2, 3, 5, 7}, {2, 3, 5, 7, 8}, {2, 3, 5, 7, 8, 9}, {2, 3, 5, 7, 8, 9, 10}, {2, 3, 5, 7, 8, 10}, {2, 3, 5, 7, 9}, {2, 3, 5, 7, 9, 10}, {2, 3, 5, 7, 10}, {2, 3, 5, 8}, {2, 3, 5, 8, 9}, {2, 3, 5, 8, 9, 10}, {2, 3, 5, 8, 10}, {2, 3, 5, 9}, {2, 3, 5, 9, 10}, {2, 3, 5, 10}, {2, 3, 6}, {2, 3, 6, 7}, {2, 3, 6, 7, 8}, {2, 3, 6, 7, 8, 9}, {2, 3, 6, 7, 8, 9, 10}, {2, 3, 6, 7, 8, 10}, {2, 3, 6, 7, 9}, {2, 3, 6, 7, 9, 10}, {2, 3, 6, 7, 10}, {2, 3, 6, 8}, {2, 3, 6, 8, 9}, {2, 3, 6, 8, 9, 10}, {2, 3, 6, 8, 10}, {2, 3, 6, 9}, {2, 3, 6, 9, 10}, {2, 3, 6, 10}, {2, 3, 7}, {2, 3, 7, 8}, {2, 3, 7, 8, 9}, {2, 3, 7, 8, 9, 10}, {2, 3, 7, 8, 10}, {2, 3, 7, 9}, {2, 3, 7, 9, 10}, {2, 3, 7, 10}, {2, 3, 8}, {2, 3, 8, 9}, {2, 3, 8, 9, 10}, {2, 3, 8, 10}, {2, 3, 9}, {2, 3, 9, 10}, {2, 3, 10}, {2, 4}, {2, 4, 5}, {2, 4, 5, 6}, {2, 4, 5, 6, 7}, {2, 4, 5, 6, 7, 8}, {2, 4, 5, 6, 7, 8, 9}, {2, 4, 5, 6, 7, 8, 9, 10}, {2, 4, 5, 6, 7, 8, 10}, {2, 4, 5, 6, 7, 9}, {2, 4, 5, 6, 7, 9, 10}, {2, 4, 5, 6, 7, 10}, {2, 4, 5, 6, 8}, {2, 4, 5, 6, 8, 9}, {2, 4, 5, 6, 8, 9, 10}, {2, 4, 5, 6, 8, 10}, {2, 4, 5, 6, 9}, {2, 4, 5, 6, 9, 10}, {2, 4, 5, 6, 10}, {2, 4, 5, 7}, {2, 4, 5, 7, 8}, {2, 4, 5, 7, 8, 9}, {2, 4, 5, 7, 8, 9, 10}, {2, 4, 5, 7, 8, 10}, {2, 4, 5, 7, 9}, {2, 4, 5, 7, 9, 10}, {2, 4, 5, 7, 10}, {2, 4, 5, 8}, {2, 4, 5, 8, 9}, {2, 4, 5, 8, 9, 10}, {2, 4, 5, 8, 10}, {2, 4, 5, 9}, {2, 4, 5, 9, 10}, {2, 4, 5, 10}, {2, 4, 6}, {2, 4, 6, 7}, {2, 4, 6, 7, 8}, {2, 4, 6, 7, 8, 9}, {2, 4, 6, 7, 8, 9, 10}, {2, 4, 6, 7, 8, 10}, {2, 4, 6, 7, 9}, {2, 4, 6, 7, 9, 10}, {2, 4, 6, 7, 10}, {2, 4, 6, 8}, {2, 4, 6, 8, 9}, {2, 4, 6, 8, 9, 10}, {2, 4, 6, 8, 10}, {2, 4, 6, 9}, {2, 4, 6, 9, 10}, {2, 4, 6, 10}, {2, 4, 7}, {2, 4, 7, 8}, {2, 4, 7, 8, 9}, {2, 4, 7, 8, 9, 10}, {2, 4, 7, 8, 10}, {2, 4, 7, 9}, {2, 4, 7, 9, 10}, {2, 4, 7, 10}, {2, 4, 8}, {2, 4, 8, 9}, {2, 4, 8, 9, 10}, {2, 4, 8, 10}, {2, 4, 9}, {2, 4, 9, 10}, {2, 4, 10}, {2, 5}, {2, 5, 6}, {2, 5, 6, 7}, {2, 5, 6, 7, 8}, {2, 5, 6, 7, 8, 9}, {2, 5, 6, 7, 8, 9, 10}, {2, 5, 6, 7, 8, 10}, {2, 5, 6, 7, 9}, {2, 5, 6, 7, 9, 10}, {2, 5, 6, 7, 10}, {2, 5, 6, 8}, {2, 5, 6, 8, 9}, {2, 5, 6, 8, 9, 10}, {2, 5, 6, 8, 10}, {2, 5, 6, 9}, {2, 5, 6, 9, 10}, {2, 5, 6, 10}, {2, 5, 7}, {2, 5, 7, 8}, {2, 5, 7, 8, 9}, {2, 5, 7, 8, 9, 10}, {2, 5, 7, 8, 10}, {2, 5, 7, 9}, {2, 5, 7, 9, 10}, {2, 5, 7, 10}, {2, 5, 8}, {2, 5, 8, 9}, {2, 5, 8, 9, 10}, {2, 5, 8, 10}, {2, 5, 9}, {2, 5, 9, 10}, {2, 5, 10}, {2, 6}, {2, 6, 7}, {2, 6, 7, 8}, {2, 6, 7, 8, 9}, {2, 6, 7, 8, 9, 10}, {2, 6, 7, 8, 10}, {2, 6, 7, 9}, {2, 6, 7, 9, 10}, {2, 6, 7, 10}, {2, 6, 8}, {2, 6, 8, 9}, {2, 6, 8, 9, 10}, {2, 6, 8, 10}, {2, 6, 9}, {2, 6, 9, 10}, {2, 6, 10}, {2, 7}, {2, 7, 8}, {2, 7, 8, 9}, {2, 7, 8, 9, 10}, {2, 7, 8, 10}, {2, 7, 9}, {2, 7, 9, 10}, {2, 7, 10}, {2, 8}, {2, 8, 9}, {2, 8, 9, 10}, {2, 8, 10}, {2, 9}, {2, 9, 10}, {2, 10}, {3, 4}, {3, 4, 5}, {3, 4, 5, 6}, {3, 4, 5, 6, 7}, {3, 4, 5, 6, 7, 8}, {3, 4, 5, 6, 7, 8, 9}, {3, 4, 5, 6, 7, 8, 9, 10}, {3, 4, 5, 6, 7, 8, 10}, {3, 4, 5, 6, 7, 9}, {3, 4, 5, 6, 7, 9, 10}, {3, 4, 5, 6, 7, 10}, {3, 4, 5, 6, 8}, {3, 4, 5, 6, 8, 9}, {3, 4, 5, 6, 8, 9, 10}, {3, 4, 5, 6, 8, 10}, {3, 4, 5, 6, 9}, {3, 4, 5, 6, 9, 10}, {3, 4, 5, 6, 10}, {3, 4, 5, 7}, {3, 4, 5, 7, 8}, {3, 4, 5, 7, 8, 9}, {3, 4, 5, 7, 8, 9, 10}, {3, 4, 5, 7, 8, 10}, {3, 4, 5, 7, 9}, {3, 4, 5, 7, 9, 10}, {3, 4, 5, 7, 10}, {3, 4, 5, 8}, {3, 4, 5, 8, 9}, {3, 4, 5, 8, 9, 10}, {3, 4, 5, 8, 10}, {3, 4, 5, 9}, {3, 4, 5, 9, 10}, {3, 4, 5, 10}, {3, 4, 6}, {3, 4, 6, 7}, {3, 4, 6, 7, 8}, {3, 4, 6, 7, 8, 9}, {3, 4, 6, 7, 8, 9, 10}, {3, 4, 6, 7, 8, 10}, {3, 4, 6, 7, 9}, {3, 4, 6, 7, 9, 10}, {3, 4, 6, 7, 10}, {3, 4, 6, 8}, {3, 4, 6, 8, 9}, {3, 4, 6, 8, 9, 10}, {3, 4, 6, 8, 10}, {3, 4, 6, 9}, {3, 4, 6, 9, 10}, {3, 4, 6, 10}, {3, 4, 7}, {3, 4, 7, 8}, {3, 4, 7, 8, 9}, {3, 4, 7, 8, 9, 10}, {3, 4, 7, 8, 10}, {3, 4, 7, 9}, {3, 4, 7, 9, 10}, {3, 4, 7, 10}, {3, 4, 8}, {3, 4, 8, 9}, {3, 4, 8, 9, 10}, {3, 4, 8, 10}, {3, 4, 9}, {3, 4, 9, 10}, {3, 4, 10}, {3, 5}, {3, 5, 6}, {3, 5, 6, 7}, {3, 5, 6, 7, 8}, {3, 5, 6, 7, 8, 9}, {3, 5, 6, 7, 8, 9, 10}, {3, 5, 6, 7, 8, 10}, {3, 5, 6, 7, 9}, {3, 5, 6, 7, 9, 10}, {3, 5, 6, 7, 10}, {3, 5, 6, 8}, {3, 5, 6, 8, 9}, {3, 5, 6, 8, 9, 10}, {3, 5, 6, 8, 10}, {3, 5, 6, 9}, {3, 5, 6, 9, 10}, {3, 5, 6, 10}, {3, 5, 7}, {3, 5, 7, 8}, {3, 5, 7, 8, 9}, {3, 5, 7, 8, 9, 10}, {3, 5, 7, 8, 10}, {3, 5, 7, 9}, {3, 5, 7, 9, 10}, {3, 5, 7, 10}, {3, 5, 8}, {3, 5, 8, 9}, {3, 5, 8, 9, 10}, {3, 5, 8, 10}, {3, 5, 9}, {3, 5, 9, 10}, {3, 5, 10}, {3, 6}, {3, 6, 7}, {3, 6, 7, 8}, {3, 6, 7, 8, 9}, {3, 6, 7, 8, 9, 10}, {3, 6, 7, 8, 10}, {3, 6, 7, 9}, {3, 6, 7, 9, 10}, {3, 6, 7, 10}, {3, 6, 8}, {3, 6, 8, 9}, {3, 6, 8, 9, 10}, {3, 6, 8, 10}, {3, 6, 9}, {3, 6, 9, 10}, {3, 6, 10}, {3, 7}, {3, 7, 8}, {3, 7, 8, 9}, {3, 7, 8, 9, 10}, {3, 7, 8, 10}, {3, 7, 9}, {3, 7, 9, 10}, {3, 7, 10}, {3, 8}, {3, 8, 9}, {3, 8, 9, 10}, {3, 8, 10}, {3, 9}, {3, 9, 10}, {3, 10}, {4, 5}, {4, 5, 6}, {4, 5, 6, 7}, {4, 5, 6, 7, 8}, {4, 5, 6, 7, 8, 9}, {4, 5, 6, 7, 8, 9, 10}, {4, 5, 6, 7, 8, 10}, {4, 5, 6, 7, 9}, {4, 5, 6, 7, 9, 10}, {4, 5, 6, 7, 10}, {4, 5, 6, 8}, {4, 5, 6, 8, 9}, {4, 5, 6, 8, 9, 10}, {4, 5, 6, 8, 10}, {4, 5, 6, 9}, {4, 5, 6, 9, 10}, {4, 5, 6, 10}, {4, 5, 7}, {4, 5, 7, 8}, {4, 5, 7, 8, 9}, {4, 5, 7, 8, 9, 10}, {4, 5, 7, 8, 10}, {4, 5, 7, 9}, {4, 5, 7, 9, 10}, {4, 5, 7, 10}, {4, 5, 8}, {4, 5, 8, 9}, {4, 5, 8, 9, 10}, {4, 5, 8, 10}, {4, 5, 9}, {4, 5, 9, 10}, {4, 5, 10}, {4, 6}, {4, 6, 7}, {4, 6, 7, 8}, {4, 6, 7, 8, 9}, {4, 6, 7, 8, 9, 10}, {4, 6, 7, 8, 10}, {4, 6, 7, 9}, {4, 6, 7, 9, 10}, {4, 6, 7, 10}, {4, 6, 8}, {4, 6, 8, 9}, {4, 6, 8, 9, 10}, {4, 6, 8, 10}, {4, 6, 9}, {4, 6, 9, 10}, {4, 6, 10}, {4, 7}, {4, 7, 8}, {4, 7, 8, 9}, {4, 7, 8, 9, 10}, {4, 7, 8, 10}, {4, 7, 9}, {4, 7, 9, 10}, {4, 7, 10}, {4, 8}, {4, 8, 9}, {4, 8, 9, 10}, {4, 8, 10}, {4, 9}, {4, 9, 10}, {4, 10}, {5, 6}, {5, 6, 7}, {5, 6, 7, 8}, {5, 6, 7, 8, 9}, {5, 6, 7, 8, 9, 10}, {5, 6, 7, 8, 10}, {5, 6, 7, 9}, {5, 6, 7, 9, 10}, {5, 6, 7, 10}, {5, 6, 8}, {5, 6, 8, 9}, {5, 6, 8, 9, 10}, {5, 6, 8, 10}, {5, 6, 9}, {5, 6, 9, 10}, {5, 6, 10}, {5, 7}, {5, 7, 8}, {5, 7, 8, 9}, {5, 7, 8, 9, 10}, {5, 7, 8, 10}, {5, 7, 9}, {5, 7, 9, 10}, {5, 7, 10}, {5, 8}, {5, 8, 9}, {5, 8, 9, 10}, {5, 8, 10}, {5, 9}, {5, 9, 10}, {5, 10}, {6, 7}, {6, 7, 8}, {6, 7, 8, 9}, {6, 7, 8, 9, 10}, {6, 7, 8, 10}, {6, 7, 9}, {6, 7, 9, 10}, {6, 7, 10}, {6, 8}, {6, 8, 9}, {6, 8, 9, 10}, {6, 8, 10}, {6, 9}, {6, 9, 10}, {6, 10}, {7, 8}, {7, 8, 9}, {7, 8, 9, 10}, {7, 8, 10}, {7, 9}, {7, 9, 10}, {7, 10}, {8, 9}, {8, 9, 10}, {8, 10}, {9, 10}}) == result);
	
	cout << "\nPassed All\n";
	return 0;
}