/*
Leetcode Problem 1920: Build Array from Permutation
---------------------------------------------------
Given a zero-based permutation nums (0-indexed) of length n, build an array ans of the same length 
where ans[i] = nums[nums[i]] for each 0 <= i < n and return it.

You must solve it without using extra space if possible.

Approach (O(1) Extra Space - Encoding Trick):
---------------------------------------------
- Since nums is a permutation of numbers from 0 to n-1, each element is less than n.
- We can store both the original value and the new value in the same array position temporarily:
    encoded_value = old_value + (new_value % n) * n
- The old value can be retrieved using modulo operation: old_value = encoded_value % n
- The new value can be retrieved using division: new_value = encoded_value / n
- Step 1: Encode both old and new values into nums[i] in one pass.
- Step 2: Decode to extract only the new values in another pass.

Time Complexity:  O(n)  - Two passes over the array
Space Complexity: O(1)  - No extra array used

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Encode old and new values into each nums[i]
        for (int i = 0; i < n; i++) {
            nums[i] += (nums[nums[i]] % n) * n;
        }
        
        // Step 2: Extract new values
        for (int i = 0; i < n; i++) {
            nums[i] /= n;
        }
        
        return nums;
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
