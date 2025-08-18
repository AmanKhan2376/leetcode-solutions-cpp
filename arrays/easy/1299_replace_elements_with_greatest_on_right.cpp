/*
LeetCode Problem 1299: Replace Elements with Greatest Element on Right Side
---------------------------------------------------------------------------
Given an array arr, replace every element in that array with the greatest element among the elements 
to its right, and replace the last element with -1. Return the modified array.

Approach (Reverse Traversal - O(n) Time, O(1) Space):
------------------------------------------------------
- Initialize greatest = -1 (for the last element).
- Traverse the array from right to left:
    - Store current element in temp.
    - Update current element to greatest.
    - Update greatest to max(greatest, temp).
- Return the modified array.

Time Complexity:  O(n)  - Single pass through the array
Space Complexity: O(1)  - In-place modification

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size() - 1;
        int greatest = -1, temp;
        for(int i = n; i >= 0; i--) {
            temp = greatest;
            greatest = max(greatest, arr[i]);
            arr[i] = temp;
        }
        return arr;
    }
};

// Example usage
int main() {
    vector<int> arr = {17,18,5,4,6,1};
    vector<int> result = Solution().replaceElements(arr);

    cout << "Modified array: ";
    for(int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
