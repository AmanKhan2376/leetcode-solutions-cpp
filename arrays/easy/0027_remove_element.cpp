/*
LeetCode Problem 27: Remove Element
-----------------------------------
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. 
The relative order of the elements may be changed. Return k after placing the first k elements 
of nums that are not equal to val.

Approach (Two-Pointer Write Index):
-----------------------------------
- Maintain a write pointer `k` starting at 0.
- Iterate through the array:
  - If nums[i] != val, assign nums[k] = nums[i] and increment k.
- At the end, k represents the count of elements not equal to val.

Time Complexity:  O(n)  - Single pass through the array
Space Complexity: O(1)  - In-place modification without extra storage
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0, n = nums.size();
        for(int i = 0; i < n; i ++) {
            if(nums[i] != val) {
                nums[k] = nums[i];
                k ++;
            }
        }
        return k;
    }
};

// Example usage
int main() {
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    int k = Solution().removeElement(nums, val);

    cout << "Result: ";
    for(int i = 0; i < k; i++) cout << nums[i] << " ";
    cout << endl;

    return 0;
}
