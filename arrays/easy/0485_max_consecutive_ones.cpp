/*
Leetcode Problem 485: Max Consecutive Ones
------------------------------------------
Given a binary array nums, return the maximum number of consecutive 1's in the array.

Approach (Linear Scan - Count Consecutive 1s):
----------------------------------------------
- Traverse through the array while maintaining a counter for current consecutive 1s.
- Reset the counter when encountering a 0.
- Update the maximum length whenever the streak ends or at the end.
- Return the maximum count found.

Time Complexity:  O(n)  - Single pass through the array
Space Complexity: O(1)  - Only uses counters
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0;
        int currCount = 0;
        for (int num : nums) {
            if (num == 1) {
                currCount++;
            } else {
                maxCount = max(maxCount, currCount);
                currCount = 0;
            }
        }
        maxCount = max(maxCount, currCount);
        return maxCount;
    }
};

// Example usage
int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    cout << "Max Consecutive Ones: " << Solution().findMaxConsecutiveOnes(nums) << endl;
    return 0;
}
