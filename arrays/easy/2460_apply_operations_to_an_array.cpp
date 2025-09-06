/*
Leetcode Problem 2460: Apply Operations to an Array
---------------------------------------------------
You are given a 0-indexed array nums of size n consisting of non-negative integers.

You must perform the following operations in order:
1. Iterate through the array:
   - If nums[i] == nums[i + 1], then nums[i] = 2 * nums[i] and nums[i + 1] = 0.
2. After performing all operations, shift all the 0's to the end of the array while keeping 
   the relative order of the non-zero elements the same.

Return the resulting array.

Approach:
---------
- First pass:
  * Traverse nums from left to right.
  * If consecutive elements are equal, double the first and set the second to zero.
- Second pass:
  * Compact non-zero elements to the front.
  * Keep a pointer j to track placement position.
- Third pass:
  * Fill remaining indices with 0.

Time Complexity:  O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        int j = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                if (i != j) {
                    nums[j] = nums[i];
                }
                j++;
            }
        }

        for (int i = j; i < n; i++) {
            nums[i] = 0;
        }
        
        return nums;
    }
};

// Example usage
int main() {
    vector<int> nums = {1, 2, 2, 1, 1, 0};
    vector<int> result = Solution().applyOperations(nums);

    cout << "Result: ";
    for (int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
