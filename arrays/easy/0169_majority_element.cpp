/*
Leetcode Problem 169: Majority Element
--------------------------------------
Given an array nums of size n, return the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times. You may assume that the majority element always exists in the array.

Approach:
---------
- Use the Boyer-Moore Voting Algorithm.
- Maintain a candidate and a count.
- Increment count if current element matches candidate.
- Decrement count otherwise.
- When count is zero, update candidate to current element.
- Candidate at the end is the majority element.

Time Complexity:  O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            } else if (nums[i] == candidate) {
                count++;
            } else {
                count--;
            }
        }
        return candidate;
    }
};

// Example usage
int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    Solution sol;
    int majority = sol.majorityElement(nums);
    cout << "Majority Element: " << majority << endl;

    return 0;
}
