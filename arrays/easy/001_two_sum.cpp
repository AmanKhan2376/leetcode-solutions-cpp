/*
Leetcode Problem 1: Two Sum
---------------------------
Given an array of integers nums and an integer target, return the indices of the two numbers 
such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the 
same element twice. You can return the answer in any order.

Approach:
---------
- Use a hash map (unordered_map in C++) to store numbers and their indices as we iterate.
- For each element nums[i], calculate the complement = target - nums[i].
- Check if the complement already exists in the hash map:
    - If yes, we have found the two indices → return them.
    - If no, store nums[i] with its index in the hash map.
- This allows finding the pair in one pass with O(1) lookups.

Time Complexity:  O(n)   
Space Complexity: O(n)   
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // 1st int for numbers -> 2nd int for their corresponding indices

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            mp[nums[i]] = i;
        }

        return {}; // as per problem constraints, this won't be reached
    }
};

// Example usage
int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = Solution().twoSum(nums, target);

    cout << "Indices: ";
    for (int idx : result) cout << idx << " ";
    cout << endl;

    return 0;
}
