/*
Leetcode Problem 2485: Find the Pivot Integer
---------------------------------------------
Given a positive integer n, find the pivot integer x such that:
    sum(1 → x) == sum(x → n)
Return the pivot integer x. If no such integer exists, return -1.

Approach (Mathematical Formula):
--------------------------------
- The condition requires:
      sum(1 → x) = sum(x → n)
  Which expands to:
      x * (x + 1) / 2 = totalSum - x * (x - 1) / 2
- Simplifying gives:
      x^2 = totalSum
  where totalSum = n * (n + 1) / 2.
- So the pivot exists only if totalSum is a perfect square.
- Compute totalSum, check if its square root is an integer, and return that value if valid.

Time Complexity:  O(1)   (direct formula check)
Space Complexity: O(1)   (constant extra space)
*/

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        int total = n * (n + 1) / 2;   // sum of 1..n
        int x = sqrt(total);           
        if (x * x == total) return x;  // check perfect square
        return -1;
    }
};

// Example usage
int main() {
    int n = 8;
    Solution sol;
    int result = sol.pivotInteger(n);
    cout << "Pivot integer (math approach): " << result << endl;
    return 0;
}
