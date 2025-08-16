/*
Leetcode Problem 283: Move Zeroes
---------------------------------
Given an integer array nums, move all 0's to the end of it while maintaining the relative order 
of the non-zero elements. Do this in-place without making a copy of the array.

Approach (Two Pointers - O(n) Time, O(1) Space):
-------------------------------------------------
- Initialize a pointer idx at 0 to track the position to place the next non-zero element.
- Iterate through the array:
    - If nums[i] is non-zero, swap it with nums[idx] (if i != idx) and increment idx.
- This moves all non-zero elements to the front and zeros naturally to the end.

Time Complexity:  O(n)  - Single pass through the array
Space Complexity: O(1)  - In-place modification

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                if (i != idx) swap(nums[idx], nums[i]);
                idx++;
            }
        }
    }
};

// Example usage
int main() {
    vector<int> nums = {0,1,0,3,12};
    Solution().moveZeroes(nums);

    cout << "Array after moving zeroes: ";
    for (int val : nums) cout << val << " ";
    cout << endl;

    return 0;
}
