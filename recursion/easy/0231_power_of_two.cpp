/*
Leetcode Problem 231: Power of Two
----------------------------------
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two if there exists an integer x such that n == 2^x.

Approach (Recursive Division):
------------------------------
- Base case: if n == 1 → true (since 2^0 = 1).
- If n <= 0 or n is odd → false.
- Otherwise, recursively call isPowerOfTwo(n/2).
- This repeatedly divides n by 2 until base case is reached.

Time Complexity:  O(log n)   (number of divisions until reaching 1)
Space Complexity: O(log n)   (due to recursive call stack)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 1) return true;
        if (n <= 0 || n % 2 != 0) return false;
        return isPowerOfTwo(n / 2);
    }
};

// Example usage
int main() {
    int n = 16;

    bool result = Solution().isPowerOfTwo(n);

    cout << n << " is power of two: " << (result ? "true" : "false") << endl;

    return 0;
}
