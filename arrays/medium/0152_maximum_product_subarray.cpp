/*
Leetcode Problem 152: Maximum Product Subarray
----------------------------------------------
Given an integer array nums, find a contiguous non-empty subarray within the array that has 
the largest product, and return the product.

Approach:
---------
- The maximum product subarray can be disrupted by negative numbers and zeros.
- Instead of just tracking max/min, here we use prefix and suffix products:
    - Traverse from the front while maintaining a running prefix product.
    - Traverse from the back while maintaining a running suffix product.
    - At each step, take the maximum of current prefix and suffix.
    - Reset prefix or suffix to 1 if they become 0 (to start fresh).
- This handles cases with negatives and zeros effectively.

Time Complexity:  O(n)   (single pass with two multiplications per step)
Space Complexity: O(1)   (constant extra space)
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largestProduct = INT_MIN, n = nums.size();
        int prefix = 1, suffix = 1;

        for (int i = 0; i < n; i++) {
            prefix *= nums[i];
            suffix *= nums[n - i - 1];
            largestProduct = max(largestProduct, max(prefix, suffix));
            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;
        }

        return largestProduct;
    }
};

// Example usage
int main() {
    vector<int> nums = {2, 3, -2, 4};
    Solution sol;
    int result = sol.maxProduct(nums);
    cout << "Maximum product subarray: " << result << endl;
    return 0;
}
