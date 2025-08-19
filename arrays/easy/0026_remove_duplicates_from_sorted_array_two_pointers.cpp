/*
LeetCode Problem 26: Remove Duplicates from Sorted Array (Two-Pointer Approach)
-------------------------------------------------------------------------------
Given a sorted array nums, remove the duplicates in-place such that each element appears only once 
and return the new length. Do not allocate extra space for another array.

Approach (Two Pointers - O(n) Time, O(1) Space):
-------------------------------------------------
- Initialize two pointers i = 0 and j = 1.
- While j < n:
    - If nums[i] != nums[j], increment i and assign nums[i] = nums[j].
    - Increment j.
- Return i + 1 as the length of unique elements.

Time Complexity:  O(n)  - Single pass through the array
Space Complexity: O(1)  - In-place modification

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = i + 1, n = nums.size();
        while(j < n) {
            if(nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
            j++;
        }
        return i + 1;
    }
};

// Example usage
int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int length = Solution().removeDuplicates(nums);

    cout << "Length of unique elements: " << length << endl;
    cout << "Array after removal: ";
    for(int i = 0; i < length; i++) cout << nums[i] << " ";
    cout << endl;

    return 0;
}
