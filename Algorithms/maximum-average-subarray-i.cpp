643. Maximum Average Subarray I
https://leetcode.com/problems/maximum-average-subarray-i/

Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75
Note:
1 <= k <= n <= 30,000.
Elements of the given array will be in the range [-10,000, 10,000].

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sz = nums.size(), window = 0, i = 0, max_window;
        while (i < k) {
            window += nums[i];
            ++i;
        }
        max_window = window;
        while (i < sz) {
            window += nums[i];
            window -= nums[i - k];
            if (max_window < window) {
                max_window = window;
            }
            ++i;
        }
        return double(max_window) / k;
    }
};

int main(void) {
    Solution solution;
    vector<int> nums;
    int k;
    double result;
    
    
    nums = {1, 12, -5, -6, 50, 3};
    k = 4;
    result = solution.findMaxAverage(nums, k);
    cout << result << '\n';
    
    return 0;
}