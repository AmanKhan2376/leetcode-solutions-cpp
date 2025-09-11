/*
Leetcode Problem 75: Sort Colors
--------------------------------
Given an array nums with n objects colored red, white, or blue (represented as 0, 1, 2), 
sort them in-place so that objects of the same color are adjacent, with the colors in 
the order red, white, and blue.

You must solve this problem without using the library's sort function.

Approach (Dutch National Flag / Two Pointers):
----------------------------------------------
- Initialize three pointers: low, mid, high.
- Traverse the array with mid:
    - If nums[mid] == 0, swap with nums[low], increment low and mid.
    - If nums[mid] == 2, swap with nums[high], decrement high (mid stays to check swapped element).
    - If nums[mid] == 1, increment mid.
- This ensures all 0s before low, all 2s after high, and 1s in between.

Time Complexity:  O(n)   (single pass)
Space Complexity: O(1)   (in-place sorting)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 2) {
                swap(nums[mid], nums[high]);
                high--;
            } else {
                mid++;
            }
        }
    }
};

// Example usage
int main() {
    vector<int> nums = {2,0,2,1,1,0};
    Solution sol;
    sol.sortColors(nums);

    cout << "Sorted colors: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    return 0;
}
