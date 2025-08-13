/*
LeetCode Problem 1281: Subtract the Product and Sum of Digits of an Integer
--------------------------------------------------------------------------
Given an integer n, return the difference between the product of its digits and the sum of its digits.

Approach:
---------
- Initialize product = 1 and sum = 0.
- While n > 0:
    - Extract the last digit using n % 10.
    - Multiply it into product.
    - Add it into sum.
    - Remove the digit by doing n /= 10.
- Return product - sum.

Time Complexity:  O(d), where d is the number of digits in n.
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1, sum = 0;
        while (n > 0) {
            int digit = n % 10;
            product *= digit;
            sum += digit;
            n /= 10;
        }
        return product - sum;
    }
};

// Example usage
int main() {
    int n = 234;
    Solution sol;
    cout << "Result: " << sol.subtractProductAndSum(n) << endl; // Output: 15
    return 0;
}
