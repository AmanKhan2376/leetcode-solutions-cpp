/*
Leetcode Problem 1464: Maximum Product of Two Elements in an Array
-------------------------------------------------------------------
Given the integer array nums, choose two different indices i and j such that 
(nums[i] - 1) * (nums[j] - 1) is maximized. Return the maximum value.

Approach (Single Scan - O(n) Time, O(1) Space):
------------------------------------------------
- Keep track of the two largest numbers in the array: first and second.
- Iterate through nums:
    - If the current number > first, update second = first, first = num.
    - Else if the current number > second, update second = num.
- Compute (first - 1) * (second - 1) and return it.

Time Complexity:  O(n)  - Single scan through the array
Space Complexity: O(1)  - Constant extra space

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first = 0, second = 0;
        for (int num : nums) {
            if (num > first) {
                second = first;
                first = num;
            } else if (num > second) {
                second = num;
            }
        }
        return (first - 1) * (second - 1);
    }
};

// Example usage
int main() {
    vector<int> nums = {3,4,5,2};
    int result = Solution().maxProduct(nums);

    cout << "Maximum product: " << result << endl;

    return 0;
}
