/*
Leetcode Problem 287: Find the Duplicate Number
-----------------------------------------------
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
there is only one repeated number. Return this duplicate number without modifying the array and using 
only constant extra space.

Approach (Floyd's Tortoise and Hare - O(n) Time, O(1) Space):
--------------------------------------------------------------
- Use two pointers (slow and fast) to detect a cycle, treating the array values as next indices.
- Move slow by one step and fast by two steps until they meet (cycle detection).
- Reset slow to the start and move both pointers one step at a time until they meet again.
- The meeting point is the duplicate number.

Time Complexity:  O(n)  - Detecting cycle and finding entry point
Space Complexity: O(1)  - Only pointers used

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

// Example usage
int main() {
    vector<int> nums = {1,3,4,2,2};
    int result = Solution().findDuplicate(nums);

    cout << "Duplicate number: " << result << endl;

    return 0;
}
