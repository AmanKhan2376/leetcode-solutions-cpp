/*
Leetcode Problem 3467: Transform Array by Parity
------------------------------------------------
You are given an integer array nums. 
Transform it such that:
- Replace every even number with 0.
- Replace every odd number with 1.
- Then, move all 1s to the end of the array while keeping 0s at the front.

Approach (Counting Evens First):
--------------------------------
1. Count the number of even elements in the array (evenCount).
2. Fill the first evenCount positions with 0s.
3. Fill the remaining positions with 1s.
4. This directly produces the required transformation without extra swaps.

Time Complexity:  O(n)  - Two passes (counting + filling)
Space Complexity: O(1)  - In-place modification
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int evenCount = 0;
        for (int x : nums) {
            if (x % 2 == 0) evenCount++;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i < evenCount) nums[i] = 0;
            else nums[i] = 1;
        }
        return nums;
    }
};

// Example usage
int main() {
    vector<int> nums = {3, 4, 2, 7, 8, 5};
    vector<int> result = Solution().transformArray(nums);

    cout << "Transformed Array: ";
    for (int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
