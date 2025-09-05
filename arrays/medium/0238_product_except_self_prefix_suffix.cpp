/*
Leetcode Problem 238: Product of Array Except Self
--------------------------------------------------
Given an integer array nums, return an array answer such that 
answer[i] is equal to the product of all the elements of nums 
except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit 
in a 32-bit integer.

Approach (Prefix + Suffix Arrays for Intuition):
------------------------------------------------
- Build a suffix product array:
    suffix[i] = product of all elements to the right of i.
- Build a prefix product array:
    prefix[i] = product of all elements to the left of i.
- For each index i:
    ans[i] = prefix[i] * suffix[i].

This solution uses extra O(n) space (prefix + suffix arrays) but 
makes the approach intuitive before optimizing further.

Time Complexity:  O(n)
Space Complexity: O(n)  (can be reduced to O(1) with in-place optimization)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffix(n);
        vector<int> prefix(n);
        vector<int> ans(n);

        int suffixProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffixProduct;
            suffixProduct *= nums[i];
        }

        int prefixProduct = 1;
        for (int i = 0; i < n; i++) {
            prefix[i] = prefixProduct;
            prefixProduct *= nums[i];
        }

        for (int i = 0; i < n; i++) {
            ans[i] = suffix[i] * prefix[i];
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
