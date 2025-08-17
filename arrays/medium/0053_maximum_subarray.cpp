/*
Leetcode Problem 53: Maximum Subarray
-------------------------------------
Given an integer array nums, find the contiguous subarray (containing at least one number) 
which has the largest sum and return its sum.

Approach (Kadane's Algorithm - O(n) Time, O(1) Space):
-------------------------------------------------------
- Initialize currentSum = 0 and ans = INT_MIN.
- Iterate through the array:
    - Add nums[i] to currentSum.
    - Update ans with the maximum of ans and currentSum.
    - If currentSum becomes negative, reset it to 0 (start new subarray).
- Return ans as the maximum subarray sum.

Time Complexity:  O(n)  - Single pass through the array
Space Complexity: O(1)  - Only integer variables used

*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), ans = INT_MIN, currentSum = 0;

        for (int i = 0; i < n; i++) {
            currentSum += nums[i];
            ans = max(ans, currentSum);
            if (currentSum < 0) currentSum = 0;
        }

        return ans;
    }
};

// Example usage
int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int result = Solution().maxSubArray(nums);

    cout << "Maximum subarray sum: " << result << endl;

    return 0;
}
