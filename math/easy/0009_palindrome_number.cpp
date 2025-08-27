/*
Leetcode Problem 9: Palindrome Number
-------------------------------------
Given an integer x, return true if x is a palindrome, and false otherwise.

An integer is a palindrome when it reads the same forward and backward.
For example, 121 is a palindrome while 123 is not.

Approach (Reverse Half of the Number):
--------------------------------------
- Negative numbers are not palindromes.
- If the number ends with 0 but is not 0 itself, it cannot be a palindrome.
- Reverse the last half of the number and compare with the first half:
  - Extract the last digit and build the reversed half.
  - Continue until reversed half >= remaining half.
- Finally, check if either:
  - x == reversed half (even length number), or
  - x == reversed half / 10 (odd length number).

This avoids reversing the entire number and prevents integer overflow.

Time Complexity:  O(log n)  - Digits are processed once
Space Complexity: O(1)      - Constant extra space
*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        int rev = 0;
        while (x > rev) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return (x == rev) || (x == rev / 10);
    }
};

// Example usage
int main() {
    int x = 121;
    cout << (Solution().isPalindrome(x) ? "True" : "False") << endl;

    x = -121;
    cout << (Solution().isPalindrome(x) ? "True" : "False") << endl;

    x = 10;
    cout << (Solution().isPalindrome(x) ? "True" : "False") << endl;

    return 0;
}
