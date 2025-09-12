/*
Leetcode Problem 209: Minimum Size Subarray Sum
-----------------------------------------------
Given an array of positive integers nums and a positive integer target, 
return the minimal length of a subarray whose sum is greater than or equal to target.  
If there is no such subarray, return 0 instead.

Approach (Sliding Window):
--------------------------
- Use two pointers (i, j) to form a window and maintain the current sum.
- Expand the window by moving j and adding nums[j] to current sum.
- Shrink the window from the left while the sum >= target:
    - Update the minimum length (j - i).
    - Subtract nums[i] and move i forward.
- If no valid subarray exists, return 0.

Time Complexity:  O(n)   (each element is added/removed at most once)
Space Complexity: O(1)   (constant extra space)
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int currSum = 0;
        int ans = INT_MAX;

        while (j < n) {
            currSum += nums[j++];

            while (currSum >= target) {
                ans = min(ans, j - i);
                currSum -= nums[i++];
            }
        }

        return (ans == INT_MAX) ? 0 : ans;
    }
};

// Example usage
int main() {
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    Solution sol;
    int result = sol.minSubArrayLen(target, nums);

    cout << "Minimum size subarray length: " << result << endl; // Expected: 2

    return 0;
}
