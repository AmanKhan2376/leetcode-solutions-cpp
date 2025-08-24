/*
Leetcode Problem 66: Plus One
------------------------------
You are given a large integer represented as an integer array digits, 
where each digits[i] is the ith digit of the integer. The digits are 
ordered from most significant to least significant in left-to-right order. 

The task is to add one to the integer and return the resulting array of digits.

Approach (Carry Propagation from End):
--------------------------------------
- Start with a carry of 1 (since we need to add one).
- Traverse the digits from the end to the start:
  - Add the carry to the current digit.
  - Update digit = sum % 10 and carry = sum / 10.
- If carry remains after the loop, insert it at the beginning.
- Return the modified array.

Time Complexity:  O(n)  - Single pass over digits
Space Complexity: O(1)  - In-place update, except possible insertion of one digit
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1; 
        for (int i = n - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        if (carry > 0) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};

// Example usage
int main() {
    vector<int> digits = {9, 9, 9};
    vector<int> result = Solution().plusOne(digits);

    cout << "Result: ";
    for (int d : result) cout << d << " ";
    cout << endl;

    return 0;
}
