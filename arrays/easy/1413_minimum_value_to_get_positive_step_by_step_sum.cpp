/*
Leetcode Problem 1413: Minimum Value to Get Positive Step by Step Sum
---------------------------------------------------------------------
Given an integer array nums, find the minimum positive integer startValue such that the step-by-step sum 
(startValue + nums[0] + nums[1] + ... + nums[i]) is always at least 1.

Approach (Prefix Sum - O(n) Time, O(1) Space):
-----------------------------------------------
- Initialize sum = 0 and minSum = 0.
- Iterate through nums:
    - Add each number to sum.
    - Update minSum to be the minimum of minSum and sum.
- The minimum startValue required is 1 - minSum to ensure the sum never goes below 1.

Time Complexity:  O(n)  - Single pass through the array
Space Complexity: O(1)  - Only two integer variables used

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int minSum = 0, sum = 0;
        for (int num : nums) {
            sum += num;
            minSum = min(minSum, sum);
        }
        return 1 - minSum;
    }
};

// Example usage
int main() {
    vector<int> nums = {-3, 2, -3, 4, 2};
    int result = Solution().minStartValue(nums);

    cout << "Minimum start value: " << result << endl;

    return 0;
}
