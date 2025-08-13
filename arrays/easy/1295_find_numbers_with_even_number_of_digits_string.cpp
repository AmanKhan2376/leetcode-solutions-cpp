/*
LeetCode Problem 1295: Find Numbers with Even Number of Digits
--------------------------------------------------------------
Given an array nums of integers, return how many of them contain an even number of digits.

Approach (String Conversion):
-----------------------------
- Iterate through each number in nums.
- Convert the number to a string and count its length.
- If the count is even, increment the answer.
- This approach uses string conversion for simplicity.

Time Complexity:  O(n * d)   // d = number of digits (string conversion cost)
Space Complexity: O(1)       // no extra data structures
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int num : nums) {
            int count = 0;
            string s = to_string(num);
            for (char digit : s) {
                count++;
            }
            if (count % 2 == 0) {
                ans++;
            }
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
