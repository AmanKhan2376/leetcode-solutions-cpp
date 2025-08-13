/*
LeetCode Problem 1295: Find Numbers with Even Number of Digits
--------------------------------------------------------------
Given an array nums of integers, return how many of them contain an even number of digits.

Approach (Mathematical Counting):
---------------------------------
- Iterate through each number in nums.
- Count digits by dividing the number by 10 repeatedly until it becomes 0.
- If the digit count is even, increment the answer.
- This avoids string conversion and is more optimal.

Time Complexity:  O(n * d)   // d = number of digits (integer division)
Space Complexity: O(1)       // no extra data structures
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int num : nums) {
            int digits = 0;
            while (num > 0) {
                num /= 10;
                digits++;
            }
            if (digits % 2 == 0) ans++;
        }
        return ans;
    }
};

// Example usage
int main() {
    vector<int> nums = {12, 345, 2, 6, 7896};
    cout << Solution().findNumbers(nums) << endl;
    return 0;
}
