/*
Leetcode Problem 378: Kth Smallest Element in a Sorted Matrix
-------------------------------------------------------------
Given an n x n matrix where each of the rows and columns is sorted in ascending order, 
return the kth smallest element in the matrix.

Approach:
---------
- Use binary search on the range of numbers [matrix[0][0], matrix[n-1][n-1]].
- For each mid value, count how many elements in the matrix are <= mid using upper_bound.
- If count < k → kth smallest is greater than mid → move low up.
- Else → move high down.
- When low == high, we have found the kth smallest element.

Time Complexity:  O(n log(max-min) * log n)   
Space Complexity: O(1)   
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n - 1][n - 1];

        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            
            for (int i = 0; i < n; i++) {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }

            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
};

// Example usage
int main() {
    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int k = 8;

    int result = Solution().kthSmallest(matrix, k);

    cout << "Kth smallest element: " << result << endl;

    return 0;
}
