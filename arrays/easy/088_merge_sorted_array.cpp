/*
Leetcode Problem 88: Merge Sorted Array
---------------------------------------
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums2 into nums1 as one sorted array in-place.

Approach:
---------
- Use two pointers starting from the ends of the valid elements in nums1 and nums2.
- Compare and insert the larger element at the end of nums1 (index k).
- Continue until all elements from nums2 are placed in nums1.
- This ensures O(m + n) time complexity and O(1) extra space.

Time Complexity:  O(m + n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;      // pointer for nums1's last valid element
        int j = n - 1;      // pointer for nums2's last element
        int k = m + n - 1;  // pointer for nums1's last position

        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};

// Example usage
int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;

    Solution().merge(nums1, m, nums2, n);

    cout << "Merged Array: ";
    for (int num : nums1) cout << num << " ";
    cout << endl;

    return 0;
}
