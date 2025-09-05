/*
Leetcode Problem 238: Product of Array Except Self
--------------------------------------------------
Given an integer array nums, return an array answer such that 
answer[i] is equal to the product of all the elements of nums 
except nums[i].

You must write an algorithm that runs in O(n) time and without 
using the division operation.

Approach (Optimal, O(1) Extra Space):
-------------------------------------
- First pass (right to left):
    * Store suffix product at each index in ans[i].
    * Keep updating suffix as product of elements to the right.
- Second pass (left to right):
    * Multiply ans[i] by prefix product so far.
    * Update prefix as product of elements to the left.

This way, ans[i] = product of all elements except nums[i].

Time Complexity:  O(n)
Space Complexity: O(1) extra space (ignoring output array)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = suffix;
            suffix *= nums[i];
        }

        int prefix = 1;
        for (int i = 0; i < n; i++) {
            ans[i] = ans[i] * prefix;
            prefix *= nums[i];
        }

        return ans;
    }
};

// Example usage
int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = Solution().productExceptSelf(nums);

    cout << "Result: ";
    for (int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
