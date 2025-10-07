/* Leetcode Problem 78: Subsets
---------------------------
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. You can return the solution in any order.

Approach:
---------
- Use backtracking to explore all subsets.
- At each index, we have two choices:
  1. Include the current element in the subset.
  2. Exclude the current element from the subset.
- Recursively build the subsets and store them in the result vector.

Time Complexity: O(2^n * n), where n = nums.size()
Space Complexity: O(n) for the recursion stack + O(2^n * n) for the result
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, vector<int>& current, int index, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(current);
            return;
        }

        // Include nums[index]
        current.push_back(nums[index]);
        backtrack(nums, current, index + 1, result);

        // Exclude nums[index]
        current.pop_back();
        backtrack(nums, current, index + 1, result);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, current, 0, result);
        return result;
    }
};

// Example usage
int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = Solution().subsets(nums);

    cout << "Subsets:\n";
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) cout << num << " ";
        cout << "]\n";
    }

    return 0;
}
