/*
Leetcode Problem 509: Fibonacci Number
--------------------------------------
The Fibonacci numbers are defined as:
F(0) = 0, F(1) = 1
F(n) = F(n-1) + F(n-2) for n > 1

Approach (Naïve Recursion):
----------------------------
- Directly apply the recursive formula definition.
- Simple but highly inefficient due to repeated calculations.

Time Complexity:  O(2^n)   (exponential, because of overlapping subproblems)
Space Complexity: O(n)     (recursive call stack depth)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n <= 1)
            return n;
        return fib(n - 1) + fib(n - 2);
    }
};

// Example usage
int main() {
    int n = 10;

    int result = Solution().fib(n);

    cout << "Fibonacci(" << n << ") = " << result << endl;

    return 0;
}
