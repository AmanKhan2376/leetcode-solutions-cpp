/*
Leetcode Problem 26: Remove Duplicates from Sorted Array
--------------------------------------------------------
Given a sorted array nums, remove the duplicates in-place such that each element appears only once 
and return the new length. Do not allocate extra space for another array.

Approach (Two Pointers - O(n) Time, O(1) Space):
-------------------------------------------------
- Initialize a pointer idx at 0 to track the position of the last unique element.
- Iterate through the array from index 1:
    - If nums[i] != nums[idx], increment idx and swap nums[i] with nums[idx].
- Return idx + 1 as the length of the unique elements.

Time Complexity:  O(n)  - Single pass through the array
Space Complexity: O(1)  - In-place modification, constant extra space

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[idx]) {
                idx++;
                swap(nums[i], nums[idx]);
            }
        }
        return idx + 1;
    }
};

// Example usage
int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int length = Solution().removeDuplicates(nums);

    cout << "Length of unique elements: " << length << endl;
    cout << "Array after removal: ";
    for (int i = 0; i < length; i++) cout << nums[i] << " ";
    cout << endl;

    return 0;
}
