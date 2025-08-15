/*
Leetcode Problem 724: Find Pivot Index
--------------------------------------
Given an integer array nums, find the pivot index, where the sum of the numbers to the left of the index 
is equal to the sum of the numbers to the right. Return the leftmost pivot index, or -1 if none exists.

Approach (Prefix Sum - O(n) Time, O(1) Space):
-----------------------------------------------
- Compute total sum of the array (rightSum).
- Initialize leftSum = 0.
- Iterate through the array:
    - Subtract nums[i] from rightSum to get sum of elements to the right of i.
    - If leftSum equals rightSum, return i.
    - Add nums[i] to leftSum for next iteration.
- Return -1 if no pivot index found.

Time Complexity:  O(n)  - Single pass through the array
Space Complexity: O(1)  - Only two integer variables used

*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size(), leftSum = 0, rightSum = accumulate(nums.begin(), nums.end(), 0);

        for (int i = 0; i < n; i++) {
            rightSum -= nums[i];
            if (leftSum == rightSum) return i;
            leftSum += nums[i];
        }

        return -1;
    }
};

// Example usage
int main() {
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    int result = Solution().pivotIndex(nums);

    cout << "Pivot index: " << result << endl;

    return 0;
}
