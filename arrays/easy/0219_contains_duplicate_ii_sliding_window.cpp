/*
Leetcode Problem 219: Contains Duplicate II
-------------------------------------------
Given an integer array nums and an integer k, return true if there are two distinct indices 
i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

Approach (Sliding Window with Hash Set):
----------------------------------------
- Maintain a sliding window of size at most k using an unordered_set.
- For each element:
  - If it already exists in the set, return true (duplicate found within window).
  - Otherwise, insert it into the set.
  - If the set size exceeds k, remove the element that falls out of the window.
- If no duplicates are found, return false.

This approach ensures we only keep track of relevant elements within distance k.

Time Complexity:  O(n)  - Each element inserted/erased at most once
Space Complexity: O(k)  - At most k elements stored in the set
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        for (int i = 0; i < nums.size(); i++) {
            if (window.find(nums[i]) != window.end()) {
                return true; 
            }
            window.insert(nums[i]);
            if (window.size() > k) {
                window.erase(nums[i - k]);
            }
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
