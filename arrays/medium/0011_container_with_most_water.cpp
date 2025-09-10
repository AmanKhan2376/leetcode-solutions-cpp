/*
Leetcode Problem 11: Container With Most Water
----------------------------------------------
You are given an integer array height of length n. There are n vertical lines drawn 
such that the two endpoints of the i-th line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container that holds the most water.
Return the maximum amount of water a container can store.

Approach (Two Pointers):
------------------------
- Initialize two pointers: left at 0 and right at n-1.
- Compute the area between left and right → area = min(height[left], height[right]) * (right - left).
- Update max area if current area is greater.
- Move the pointer pointing to the shorter line inward (since a taller line may give more area).
- Repeat until left >= right.

Time Complexity:  O(n)   (each pointer moves at most n steps)
Space Complexity: O(1)   (constant extra space)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxAreaOfWater = 0;

        while (left < right) {
            int area = min(height[left], height[right]) * (right - left);
            maxAreaOfWater = max(maxAreaOfWater, area);

            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxAreaOfWater;
    }
};

// Example usage
int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution sol;
    int result = sol.maxArea(height);

    cout << "Maximum water area: " << result << endl;

    return 0;
}
