/*
LeetCode Problem 42: Trapping Rain Water
----------------------------------------
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.

Approach (Two Pointers - O(n) Time, O(1) Space):
------------------------------------------------
- Initialize two pointers, left and right, at the start and end of the array.
- Maintain leftMax and rightMax for the maximum heights seen so far from both ends.
- While left < right:
    - If height[left] < height[right]:
        - If height[left] >= leftMax, update leftMax.
        - Else, add leftMax - height[left] to ans.
        - Increment left.
    - Else:
        - If height[right] >= rightMax, update rightMax.
        - Else, add rightMax - height[right] to ans.
        - Decrement right.
- Return ans as total trapped water.

Time Complexity:  O(n)  - Single pass through the array
Space Complexity: O(1)  - Constant extra space

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;

        while(left < right) {
            if(height[left] < height[right]) {
                if(height[left] >= leftMax) {
                    leftMax = height[left];  
                } else {
                    ans += leftMax - height[left]; 
                }
                left++;
            } else {
                if(height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    ans += rightMax - height[right];
                }
                right--;
            }
        }
        return ans;
    }
};

// Example usage
int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result = Solution().trap(height);

    cout << "Trapped water: " << result << endl;

    return 0;
}
