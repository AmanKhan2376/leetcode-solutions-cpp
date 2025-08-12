/*
Leetcode Problem 1920: Build Array from Permutation
---------------------------------------------------
Given a zero-based permutation nums (0-indexed) of length n, build an array ans of the same length 
where ans[i] = nums[nums[i]] for each 0 <= i < n and return it.

Approach (O(n) Extra Space - Direct Construction):
--------------------------------------------------
- Create a new array ans of size n.
- For each index i, set ans[i] = nums[nums[i]].
- Return ans.

This is the most straightforward solution, easy to understand and implement.
It requires O(n) extra space for ans, which is fine for this problem unless explicitly 
required to do it in-place.

Time Complexity:  O(n)  - One pass through the array
Space Complexity: O(n)  - Additional array ans of size n

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
};

// Example usage
int main() {
    vector<int> nums = {0, 2, 1, 5, 3, 4};
    vector<int> result = Solution().buildArray(nums);

    cout << "Result: ";
    for (int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
