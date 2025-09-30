/*
Leetcode Problem 67: Add Binary
-------------------------------
Given two binary strings a and b, return their sum as a binary string.

Approach:
---------
- Use two pointers starting from the end of strings a and b.
- Maintain a carry variable.
- While iterating:
  * Add corresponding digits from a and b along with carry.
  * Append sum % 2 to the result string.
  * Update carry = sum / 2.
- After loop, reverse the result string to get the final answer.

Time Complexity:  O(max(n, m))   where n and m are lengths of a and b
Space Complexity: O(max(n, m))   (for result string)
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.size() - 1, j = b.size() - 1, carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            res += (sum % 2) + '0';
            carry = sum / 2;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

// Example usage
int main() {
    string a = "1010", b = "1011";
    string result = Solution().addBinary(a, b);
    cout << "Sum: " << result << endl;
    return 0;
}
