/*
Leetcode Problem 704: Binary Search
-----------------------------------
Given an array of integers nums which is sorted in ascending order, 
and an integer target, write a function to search target in nums. 
If target exists, then return its index. Otherwise, return -1.

Approach:
---------
- Use binary search on the sorted array.
- Maintain two pointers: start and end.
- Repeatedly calculate mid = start + (end - start) / 2.
- If nums[mid] == target → return mid.
- If nums[mid] < target → search right half.
- If nums[mid] > target → search left half.
- If not found, return -1.

Time Complexity:  O(log n)   (binary search halves the search space each iteration)
Space Complexity: O(1)       (no extra space used)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        int mid;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
};

// Example usage
int main() {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    int result = Solution().search(nums, target);

    cout << "Index of target: " << result << endl;

    return 0;
}
