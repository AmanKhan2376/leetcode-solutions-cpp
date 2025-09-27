/*
Leetcode Problem 509: Fibonacci Number
--------------------------------------
The Fibonacci numbers, commonly denoted F(n), form a sequence, called the Fibonacci sequence, 
such that each number is the sum of the two preceding ones, starting from 0 and 1.

F(0) = 0, F(1) = 1
F(n) = F(n-1) + F(n-2) for n > 1

Approach (Iterative - Bottom Up):
---------------------------------
- Directly compute Fibonacci numbers iteratively to avoid recursion overhead.
- Use only two variables to store last two computed values.
- Start from 2 up to n and update values.

Time Complexity:  O(n)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        int prev2 = 0, prev1 = 1, cur;
        for (int i = 2; i <= n; i++) {
            cur = prev1 + prev2;
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};

// Example usage
int main() {
    int n = 10;

    int result = Solution().fib(n);

    cout << "Fibonacci(" << n << ") = " << result << endl;

    return 0;
}
