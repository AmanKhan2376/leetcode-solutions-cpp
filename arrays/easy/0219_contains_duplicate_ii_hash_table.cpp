/*
Leetcode Problem 219: Contains Duplicate II
-------------------------------------------
Given an integer array nums and an integer k, return true if there are two distinct indices 
i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

Approach (Hash Map - Track Last Seen Index):
--------------------------------------------
- Use an unordered_map to store each number’s last index.
- While iterating:
  - If the number is already in the map, check if the distance between 
    the current index and stored index <= k.
  - If yes, return true.
- Otherwise, update the index of the current number.
- If no such pair is found, return false.

Time Complexity:  O(n)  - Single pass over array
Space Complexity: O(n)  - Hash map storing indices
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.count(nums[i]) && i - mp[nums[i]] <= k) return true;
            mp[nums[i]] = i;
        }
        return false;
    }
};

// Example usage
int main() {
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;
    cout << (Solution().containsNearbyDuplicate(nums, k) ? "True" : "False") << endl;

    nums = {1, 0, 1, 1};
    k = 1;
    cout << (Solution().containsNearbyDuplicate(nums, k) ? "True" : "False") << endl;

    nums = {1, 2, 3, 1, 2, 3};
    k = 2;
    cout << (Solution().containsNearbyDuplicate(nums, k) ? "True" : "False") << endl;

    return 0;
}
