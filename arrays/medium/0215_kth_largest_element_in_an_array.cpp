/*
Leetcode Problem 215: Kth Largest Element in an Array
-----------------------------------------------------
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Approach (Quickselect):
-----------------------
- Quickselect algorithm is used, inspired by QuickSort.
- Choose the first element as pivot.
- Partition the array:
    - Place elements greater than pivot to the left.
    - Place elements smaller than pivot to the right.
- After partition, if pivot index = k-1, we found the kth largest element.
- Else adjust search boundaries accordingly and repeat.

Time Complexity:  O(n) on average, O(n^2) in worst case (unbalanced partitions).
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int partition_algorithm(vector<int>& nums, int L, int R) {
        int P = nums[L];
        int i = L + 1, j = R;

        while (i <= j) {
            if (nums[i] < P && nums[j] > P) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            if (nums[i] >= P) {
                i++;
            }
            if (nums[j] <= P) {
                j--;
            }
        }

        swap(nums[L], nums[j]);

        return j;
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int L = 0, R = n - 1;
        int pivot_idx = 0;

        while (true) {
            pivot_idx = partition_algorithm(nums, L, R);

            if (pivot_idx == k - 1) {
                break;
            } else if (pivot_idx > k - 1) {
                R = pivot_idx - 1;
            } else {
                L = pivot_idx + 1;
            }
        }

        return nums[pivot_idx];
    }
};

// Example usage
int main() {
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;

    int result = Solution().findKthLargest(nums, k);

    cout << k << "th largest element: " << result << endl;

    return 0;
}
