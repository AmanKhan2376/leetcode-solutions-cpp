/*
LeetCode Problem 3512: Minimum Operations to Make Array Sum Divisible by K
------------------------------------------------------------------------
Given an integer array nums and an integer k, you can perform the operation:
- Select an index i and replace nums[i] with nums[i] - 1.

Return the minimum number of operations required to make the sum of the array divisible by k.

Approach (Sum modulo k):
------------------------
- Compute the total sum S of the array.
- If S % k == 0: return 0.
- Else: return S % k, since each operation reduces the sum by 1.

Time Complexity:  O(n)    — one pass to compute sum  
Space Complexity: O(1)    — constant extra space
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        return sum % k;
    }
};

// Example usage
int main() {
    vector<int> nums1 = {3, 9, 7};
    int k1 = 5;
    cout << "Ops needed: " << Solution().minOperations(nums1, k1) << " (Expected: 4)" << endl;

    vector<int> nums2 = {4, 1, 3};
    int k2 = 4;
    cout << "Ops needed: " << Solution().minOperations(nums2, k2) << " (Expected: 0)" << endl;

    vector<int> nums3 = {3, 2};
    int k3 = 6;
    cout << "Ops needed: " << Solution().minOperations(nums3, k3) << " (Expected: 5)" << endl;

    return 0;
}
