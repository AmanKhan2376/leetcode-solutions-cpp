/*
LeetCode Problem 1512: Number of Good Pairs
-------------------------------------------
Given an array of integers nums, a pair (i, j) is called good if nums[i] == nums[j] and i < j.
Return the total number of good pairs.

Approach (Brute-force):
-----------------------
- Initialize count = 0.
- Use two nested loops: for each i < j, check if nums[i] == nums[j].
- Increment count if the pair is good.
- Return count.

Time Complexity:  O(n^2)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] == nums[j]) count++;
            }
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
