/*
Leetcode Problem 169: Majority Element
--------------------------------------
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times.
You may assume that the majority element always exists in the array.

Approach (Hash Map Based):
--------------------------
- Use an unordered_map to count occurrences of each element.
- Iterate through the nums array and increment frequency.
- Track the element with the maximum frequency.
- Since the majority element always exists, return the one with count > n/2.

Note: Optimal solutions exist (Boyer-Moore Voting Algorithm, O(1) space), 
but this hash map solution is simple and intuitive.

Time Complexity:  O(n)   (single pass for counting, one pass for max frequency check)
Space Complexity: O(n)   (hash map to store frequencies)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;

        for (int num : nums) {
            count[num]++;
        }

        int ans = -1, freq = -1;
        for (auto& p : count) {
            if (p.second > freq) {
                ans = p.first;
                freq = p.second;
            }
        }

        return ans;
    }
};

// Example usage
int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    Solution sol;
    int result = sol.majorityElement(nums);

    cout << "Majority element: " << result << endl;

    return 0;
}
