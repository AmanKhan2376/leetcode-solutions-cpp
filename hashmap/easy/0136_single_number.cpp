/*
Leetcode Problem 136: Single Number
-----------------------------------
Given a non-empty array of integers nums, every element appears twice except for one. 
Find that single one.

You must implement a solution with linear runtime complexity and use only constant extra space.

Approach (Hash Map Based):
--------------------------
- Use an unordered_map to count the frequency of each number.
- Iterate over nums and increment count for each element.
- Iterate over the map to find the element with frequency = 1.
- Return that element.

Note: This uses extra space, unlike the optimal XOR approach.

Time Complexity:  O(n)   (two passes: one for counting, one for checking)
Space Complexity: O(n)   (hash map to store frequencies)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        for (auto& p : freq) {
            if (p.second == 1) {
                return p.first;
            }
        }
        return 0; // should never reach here as per problem constraints
    }
};

// Example usage
int main() {
    vector<int> nums = {4, 1, 2, 1, 2};
    Solution sol;
    int result = sol.singleNumber(nums);

    cout << "Single number: " << result << endl;

    return 0;
}
