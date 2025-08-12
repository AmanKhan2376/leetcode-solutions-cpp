/*
Leetcode Problem 1929: Concatenation of Array
---------------------------------------------
Given an integer array nums of length n, return an array ans of length 2n where
ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n.

Approach:
---------
- Create a new vector ans of size 2 * n.
- Use a single loop from 0 to 2 * n - 1.
- Assign ans[i] = nums[i % n], which cycles through nums twice.
- This avoids manual index reset and simplifies code.

Time Complexity:  O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2 * n);
        for (int i = 0; i < 2 * n; i++) {
            ans[i] = nums[i % n];
        }
        return ans;
    }
};

// Example usage
int main() {
    vector<int> nums = {1, 2, 3};
    vector<int> result = Solution().getConcatenation(nums);

    cout << "Concatenated array: ";
    for (int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
