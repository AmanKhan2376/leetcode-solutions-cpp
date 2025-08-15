/*
Leetcode Problem 2574: Left and Right Sum Differences
------------------------------------------------------
Given a 0-indexed integer array nums, for each index i, find the absolute difference between the sum of 
elements to the left of i and the sum of elements to the right of i. Return the answer array.

Approach (Prefix Sum - O(n) Time, O(1) Extra Space for Sums):
--------------------------------------------------------------
- Compute the total sum of the array (rs).
- Initialize ls = 0 for the left sum.
- For each index i:
    - Subtract nums[i] from rs to get the right sum for index i.
    - Calculate the absolute difference between ls and rs, store in ans[i].
    - Add nums[i] to ls for the next iteration.

Time Complexity:  O(n)  - Single pass through the array
Space Complexity: O(n)  - Output array ans of size n

*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int ls = 0, rs = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            rs -= nums[i];                       
            ans[i] = abs(ls - rs);               
            ls += nums[i];
        }
        return ans;
    }
};

// Example usage
int main() {
    vector<int> nums = {10, 4, 8, 3};
    vector<int> result = Solution().leftRightDifference(nums);

    cout << "Result: ";
    for (int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
