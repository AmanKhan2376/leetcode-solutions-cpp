/*
Leetcode Problem 31: Next Permutation
-------------------------------------
A permutation of an array of integers is the rearrangement of its members into a 
different sequence or order.

The next permutation of an array of integers is the next lexicographically greater 
permutation of its integer sequence. If such an arrangement is not possible, it must 
be rearranged as the lowest possible order (sorted in ascending order).

Approach:
---------
1. Find the pivot:
   - Traverse from right to left and find the first index 'pivot' such that nums[pivot] < nums[pivot + 1].
   - If no such index exists, the sequence is the highest permutation → reverse the array.

2. Reverse the suffix:
   - Reverse the subarray from pivot + 1 to end to get the smallest possible arrangement.

3. Find the next greater element:
   - Traverse from pivot + 1 onwards to find the first element greater than nums[pivot].
   - Swap it with nums[pivot].

Time Complexity:  O(n)   (single pass with constant extra work)
Space Complexity: O(1)   (in-place modification)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;

        // Step 1: Find pivot
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // If no pivot, reverse whole array
        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Reverse suffix
        reverse(nums.begin() + pivot + 1, nums.end());

        // Step 3: Find just larger element and swap
        for (int i = pivot + 1; i < n; i++) {
            if (nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                return;
            }
        }
    }
};

// Example usage
int main() {
    vector<int> nums = {4, 3, 2, 5, 3, 1};
    Solution().nextPermutation(nums);

    cout << "Next permutation: ";
    for (int num : nums) cout << num << " ";
    cout << endl;

    return 0;
}
