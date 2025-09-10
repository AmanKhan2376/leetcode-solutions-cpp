/*
Leetcode Problem 2610: Convert an Array Into a 2D Array With Conditions
-----------------------------------------------------------------------
You are given an integer array nums.

You need to convert nums into a 2D array with the following conditions:
- The 2D array should contain only the elements of nums.
- Each row in the 2D array contains distinct integers.
- The number of rows should be minimized.

Return the resulting 2D array. The test cases are generated in such a way that there 
is always at least one valid answer.

Approach (Hash Map Frequency Tracking):
---------------------------------------
- Use a hash map (unordered_map) to track how many times each number has been placed.
- For each number:
    - Its occurrence index (freq[num]) determines the row it belongs to.
    - If that row does not exist yet, create a new row.
    - Place the number in that row and increment its frequency.
- This ensures:
    - Each row has distinct numbers.
    - The number of rows is minimized.

Time Complexity:  O(n)   (single pass through nums, each insertion O(1) on average)
Space Complexity: O(n)   (hash map + result storage)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> freq;

        for (int num : nums) {
            int row = freq[num]++;
            if (ans.size() <= row) ans.push_back({});
            ans[row].push_back(num);
        }

        return ans;
    }
};

// Example usage
int main() {
    vector<int> nums = {1,3,4,1,2,3,1};
    Solution sol;
    vector<vector<int>> result = sol.findMatrix(nums);

    cout << "Converted 2D array:" << endl;
    for (auto& row : result) {
        for (int num : row) cout << num << " ";
        cout << endl;
    }

    return 0;
}
