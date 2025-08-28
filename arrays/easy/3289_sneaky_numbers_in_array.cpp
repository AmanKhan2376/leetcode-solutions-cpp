/*
Leetcode Problem 3289: Sneaky Numbers in Array
----------------------------------------------
You are given an integer array nums of length n where each number is between 0 and n-1 inclusive.
A sneaky number is a number that appears exactly twice in nums.
Return a list of all sneaky numbers in ascending order.

Approach (Index Marking with Counting Trick):
---------------------------------------------
- Use the fact that all numbers are in the range [0, n-1].
- For each number nums[i], compute its index = nums[i] % n.
- Add n to nums[index] to mark another occurrence.
- After processing:
  - If nums[i] / n == 2, it means the number i appeared twice.
- Collect all such numbers into the result.

Time Complexity:  O(n)  - Two passes through nums
Space Complexity: O(1)  - In-place counting without extra storage
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int idx = nums[i] % n;
            nums[idx] += n;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] / n == 2) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// Example usage
int main() {
    vector<int> nums = {0, 1, 2, 2, 3, 0};
    vector<int> result = Solution().getSneakyNumbers(nums);

    cout << "Sneaky Numbers: ";
    for (int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
