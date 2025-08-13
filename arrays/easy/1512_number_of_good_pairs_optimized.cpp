/*
LeetCode Problem 1512: Number of Good Pairs (Optimized)
-------------------------------------------------------
Given an array of integers nums, a pair (i, j) is called good if nums[i] == nums[j] and i < j.
Return the total number of good pairs.

Approach (Optimized using Hash Map):
------------------------------------
- Use a hash map (unordered_map) to count frequency of each number as we iterate.
- For each number, the number of good pairs formed is equal to the current frequency of that number.
- Increment the frequency in the map after counting.
- Return the total count.

Time Complexity:  O(n), single pass through the array.
Space Complexity: O(n), for storing frequencies in the hash map.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> freq;
        int count = 0;
        for (int num : nums) {
            count += freq[num];  // each previous occurrence forms a good pair
            freq[num]++;
        }
        return count;
    }
};

// Example usage
int main() {
    vector<int> nums = {1, 2, 3, 1, 1, 3};
    Solution sol;
    cout << "Number of Good Pairs: " << sol.numIdenticalPairs(nums) << endl; // Output: 4
    return 0;
}
