/*
Leetcode Problem 977: Squares of a Sorted Array
---------------------------------------------------
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number 
sorted in non-decreasing order.

Approach (Two Pointers - O(n) Time, O(n) Space):
--------------------------------------------------
- Initialize two pointers: left at 0 and right at n-1.
- Create a result array of the same size as nums.
- Fill the result array from the end:
    - Compare absolute values of nums[left] and nums[right].
    - Place the larger square at the current position and move the corresponding pointer.
- Continue until left > right.
- Return the result array.

This approach leverages the fact that the input array is sorted, so the largest squares will be at the ends.

Time Complexity:  O(n)  - One pass through the array
Space Complexity: O(n)  - Additional array result of size n

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);  
        int left = 0, right = n - 1;
        int pos = n - 1;     

        while (left <= right) {
            if (abs(nums[left]) > abs(nums[right])) {
                result[pos] = nums[left] * nums[left];
                left++;
            } else {
                result[pos] = nums[right] * nums[right];
                right--;
            }
            pos--;
        }

        return result;
    }
};

// Example usage
int main() {
    vector<int> nums = {-7, -3, 2, 3, 11};
    vector<int> result = Solution().sortedSquares(nums);

    cout << "Result: ";
    for (int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
