/*
Leetcode Problem 1480: Running Sum of 1d Array
----------------------------------------------
Given an array nums, return the running sum where runningSum[i] is the sum of nums[0] to nums[i].

Approach:
---------
- Initialize a variable sum = 0.
- Iterate through the array, keep adding the current element to sum.
- Update the current element with the running sum.
- Return the updated array.

Time Complexity:  O(n)
Space Complexity: O(1) - in-place modification
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            nums[i] = sum;
        }
        return nums;
    }
};

// Example usage
int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = Solution().runningSum(nums);

    cout << "Running Sum: ";
    for (int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
