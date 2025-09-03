/*
Leetcode Problem 3028: Ant on the Boundary
------------------------------------------
An ant is traveling on a number line. You are given an integer array nums of size n, 
where nums[i] is the ith movement of the ant.

The ant starts at position 0.  
Return the number of times the ant returns to position 0 after making a move.

Approach:
---------
- Start with position = 0 and count = 0.
- Iterate through nums:
    - Add each step to current position.
    - If position becomes 0, increment count.
- Return the final count.

Time Complexity:  O(n)   (single traversal of nums)
Space Complexity: O(1)   (constant extra space)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int position = 0, count = 0;
        for (int steps : nums) {
            position += steps;
            if (position == 0) count++;
        }
        return count;
    }
};

// Example usage
int main() {
    vector<int> nums = {2, 3, -5};
    Solution sol;
    int result = sol.returnToBoundaryCount(nums);
    cout << "Times ant returns to boundary: " << result << endl;
    return 0;
}
