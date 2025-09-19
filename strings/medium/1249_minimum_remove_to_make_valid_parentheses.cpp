/*
Leetcode Problem 1249: Minimum Remove to Make Valid Parentheses
---------------------------------------------------------------
Given a string s of '(' , ')' and lowercase English characters, remove the minimum number 
of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid. 
Return any valid string.

Approach:
---------
- Traverse the string from left to right:
    - Count '(' as open parentheses.
    - If ')' is encountered without a matching '(', mark it for removal (using a placeholder like '#').
    - Otherwise, decrement the open counter.
- Traverse from right to left:
    - Count ')' as close parentheses.
    - If '(' is encountered without a matching ')', mark it for removal.
- Remove all placeholders and return the resulting valid string.

Time Complexity:  O(n)   (two passes + erase)
Space Complexity: O(1)   (in-place modification)
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0;
        int close = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                open++;
            } else if (s[i] == ')') {
                if (open == 0) {
                    s[i] = '#';
                } else {
                    open--;
                }
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')') {
                close++;
            } else if (s[i] == '(') {
                if (close == 0) {
                    s[i] = '#';
                } else {
                    close--;
                }
            }
        }

        s.erase(remove(s.begin(), s.end(), '#'), s.end());

        return s;
    }
};

// Example usage
int main() {
    string s = "lee(t(c)o)de)";

    string result = Solution().minRemoveToMakeValid(s);

    cout << "Valid parentheses string: " << result << endl;

    return 0;
}
