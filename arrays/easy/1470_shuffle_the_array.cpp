/*
Leetcode Problem 1470: Shuffle the Array
----------------------------------------
Given an array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn],
return the array in the form [x1,y1,x2,y2,...,xn,yn].

Approach:
---------
- Initialize two pointers: one at the start (x), one at n (y).
- Create an answer vector of size 2n.
- Iterate over indices from 0 to 2n-1.
- If index is even, assign ans[i] = nums[x++].
- Else assign ans[i] = nums[y++].
- Return the answer array.

Time Complexity:  O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2 * n);
        int x = 0, y = n;
        for (int i = 0; i < 2 * n; i ++) {
            if (i % 2 == 0) {
                ans[i] = nums[x ++];
            } else {
                ans[i] = nums[y ++];
            }
        }
        return ans;
    }
};

// Example usage
int main() {
    vector<int> nums = {2, 5, 1, 3, 4, 7};
    int n = 3;
    vector<int> result = Solution().shuffle(nums, n);

    cout << "Shuffled Array: ";
    for (int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
