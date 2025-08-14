/*
Leetcode Problem 1991: Find the Middle Index in Array
-----------------------------------------------------
Given a 0-indexed integer array nums, find the leftmost middle index 
where the sum of the elements to the left is equal to the sum of the elements to the right. 
Return -1 if no such index exists.

Approach (Prefix Sum - O(n) Time, O(1) Space):
-----------------------------------------------
- Compute the total sum of the array (rightSum).
- Initialize leftSum = 0.
- Iterate through the array:
    - Subtract nums[i] from rightSum to get the sum to the right of index i.
    - If leftSum equals rightSum, return i.
    - Add nums[i] to leftSum for next iteration.
- If no index satisfies the condition, return -1.

Time Complexity:  O(n)  - Single pass through the array
Space Complexity: O(1)  - Only two integer variables used

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int leftSum = 0, rightSum = 0;
        for (int num : nums) {
            rightSum += num;
        }
        for (int i = 0; i < nums.size(); i++) {
            rightSum -= nums[i];        
            if (leftSum == rightSum) return i;
            leftSum += nums[i];         
        }
        return -1; 
    }
};

// Example usage
int main() {
    vector<int> nums = {2, 3, -1, 8, 4};
    int result = Solution().findMiddleIndex(nums);

    cout << "Middle index: " << result << endl;

    return 0;
}
