/*
LeetCode Problem 448: Find All Numbers Disappeared in an Array
-------------------------------------------------------------
Given an array nums of n integers where nums[i] is in the range [1, n], some numbers appear twice 
and others appear once. Return an array of all the integers in the range [1, n] that do not appear in nums.

Approach (In-Place Marking - O(n) Time, O(1) Extra Space):
-----------------------------------------------------------
- Iterate through nums and for each value nums[i]:
    - Compute index = abs(nums[i]) - 1.
    - Mark nums[index] as negative to indicate presence.
- Iterate through nums again:
    - Indices with positive values correspond to missing numbers.
- Collect missing numbers in result array.

Time Complexity:  O(n)  - Two passes through the array
Space Complexity: O(1)  - In-place marking (ignoring output array)

*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i ++) {
            int present = abs(nums[i]) - 1;
            if(nums[present] > 0) nums[present] = -nums[present];
        }
        vector<int> result;
        for(int i = 0; i < n; i ++) {
            if(nums[i] > 0) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};

// Example usage
int main() {
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> result = Solution().findDisappearedNumbers(nums);

    cout << "Disappeared numbers: ";
    for(int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
