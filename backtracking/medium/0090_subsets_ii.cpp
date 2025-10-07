/* Leetcode Problem 90: Subsets II
---------------------------
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. You can return the solution in any order.

Approach:
---------
- Sort the input array to group duplicates together.
- Use backtracking to explore all subsets.
- At each index, we have two choices:
  1. Include the current element in the subset.
  2. Exclude the current element and skip all duplicates.
- Recursively build the subsets and store them in the result vector.

Time Complexity: O(2^n * n), where n = nums.size()
Space Complexity: O(n) for recursion stack + O(2^n * n) for result storage
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, int i, vector<int>& ans, vector<vector<int>>& result) {
        if (i == nums.size()) {
            result.push_back(ans);
            return;
        }

        // Include nums[i]
        ans.push_back(nums[i]);
        backtrack(nums, i + 1, ans, result);

        // Exclude nums[i] and skip duplicates
        ans.pop_back();
        int idx = i + 1;
        while (idx < nums.size() && nums[idx] == nums[idx - 1]) idx++;
        backtrack(nums, idx, ans, result);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> ans;
        backtrack(nums, 0, ans, result);
        return result;
    }
};

// Example usage
int main() {
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = Solution().subsetsWithDup(nums);

    cout << "Subsets with duplicates handled:\n";
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) cout << num << " ";
        cout << "]\n";
    }

    return 0;
}
