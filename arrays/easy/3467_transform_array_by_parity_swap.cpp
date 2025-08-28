/*
Leetcode Problem 3467: Transform Array by Parity
------------------------------------------------
You are given an integer array nums. 
Transform it such that:
- Replace every even number with 0.
- Replace every odd number with 1.
- Then, move all 1s to the end of the array while keeping 0s at the front.

Approach (In-place Transformation + Two-pointer Partitioning):
--------------------------------------------------------------
1. First pass:
   - Iterate through nums and replace each element:
     * Even -> 0
     * Odd  -> 1
2. Second pass:
   - Use two pointers:
     * start begins from 0
     * end begins from n-1
   - While start < end:
     * If nums[start] is 1, swap with nums[end] and decrement end.
     * Otherwise, move start forward.
3. Return the modified array.

Time Complexity:  O(n)  - Two linear passes
Space Complexity: O(1)  - In-place modification
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = (nums[i] % 2 == 0 ? 0 : 1);
        }
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            if (nums[start] == 1) {
                swap(nums[start], nums[end]);
                end--;
            } else {
                start++;
            }
        }
        return nums;
    }
};

// Example usage
int main() {
    vector<int> nums = {3, 4, 2, 7, 8, 5};
    vector<int> result = Solution().transformArray(nums);

    cout << "Transformed Array: ";
    for (int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
