/*
Leetcode Problem 2485: Find the Pivot Integer
---------------------------------------------
Given a positive integer n, find the pivot integer x such that:
    sum(1 → x) == sum(x → n)
Return the pivot integer x. If no such integer exists, return -1.

Approach (Two Pointer Simulation):
----------------------------------
- Initialize two pointers:
    - leftIdx starting at 1 with running sum leftSum.
    - rightIdx starting at n with running sum rightSum.
- Move the pointers inward:
    - If leftSum < rightSum → add leftIdx to leftSum and move leftIdx forward.
    - Otherwise → add rightIdx to rightSum and move rightIdx backward.
- Continue until leftIdx == rightIdx.
- If at that point leftSum == rightSum, return leftIdx (pivot).
- Otherwise, return -1.

Time Complexity:  O(n)   (each number is processed once)
Space Complexity: O(1)   (constant extra space)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        int leftIdx = 1, rightIdx = n;
        int leftSum = 0, rightSum = 0;
        while (leftIdx != rightIdx) {
            if (leftSum < rightSum) leftSum += leftIdx++;
            else rightSum += rightIdx--;
        }
        if (leftSum == rightSum) return leftIdx;
        return -1;
    }
};

// Example usage
int main() {
    int n = 8;
    Solution sol;
    int result = sol.pivotInteger(n);
    cout << "Pivot integer: " << result << endl;
    return 0;
}
