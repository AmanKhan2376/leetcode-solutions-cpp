/*
Leetcode Problem 485: Max Consecutive Ones
------------------------------------------
Given a binary array nums, return the maximum number of consecutive 1's in the array.

Approach:
---------
- Initialize two counters: `count` for the current streak of 1's, `maxCount` for the maximum streak.
- Iterate through the array:
    - If the current element is 1, increment `count` and update `maxCount`.
    - If the current element is 0, reset `count` to 0.
- Return `maxCount` after finishing the iteration.

Time Complexity:  O(n)   (single pass through the array)
Space Complexity: O(1)   (constant extra space)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0, count = 0;
        for (int num : nums) {
            if (num == 1) {
                count++;
                maxCount = max(maxCount, count);
            } else {
                count = 0;
            }
        }
        return maxCount;
    }
};

// Example usage
int main() {
    vector<int> nums = {1,1,0,1,1,1};
    Solution sol;
    int result = sol.findMaxConsecutiveOnes(nums);

    cout << "Maximum consecutive ones: " << result << endl;

    return 0;
}
