/*
Leetcode Problem 35: Search Insert Position
-------------------------------------------
Given a sorted array of distinct integers and a target value, return the index 
if the target is found. If not, return the index where it would be if it were inserted in order.

Approach (Binary Search):
--------------------------
- Use binary search to locate the target in the sorted array.
- If found, return its index.
- If not found, return the position where it should be inserted (end + 1 after the loop).
- This ensures O(log n) efficiency.

Time Complexity:  O(log n)  - Binary search
Space Complexity: O(1)      - Constant extra space
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0, end = n - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return end + 1;
    }
};

// Example usage
int main() {
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    cout << "Search Insert Position: " << Solution().searchInsert(nums, target) << endl;

    target = 2;
    cout << "Search Insert Position: " << Solution().searchInsert(nums, target) << endl;

    target = 7;
    cout << "Search Insert Position: " << Solution().searchInsert(nums, target) << endl;

    return 0;
}
