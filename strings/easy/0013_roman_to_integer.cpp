/*
LeetCode Problem 13: Roman to Integer
-------------------------------------
Roman numerals are represented by seven symbols:
I (1), V (5), X (10), L (50), C (100), D (500), M (1000).

Rules:
- Normally, values are added from left to right.
- If a smaller value precedes a larger one, it is subtracted.
  Example: IV = 5 - 1 = 4

Approach:
---------
- Map each Roman symbol to its integer value.
- Iterate through the string:
  * If current value < next value → subtract this value.
  * Otherwise → add this value.
- Accumulate result.

Time Complexity:  O(n), where n = length of string
Space Complexity: O(1), fixed symbol table
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int values[128] = {0};
        values['I'] = 1;
        values['V'] = 5;
        values['X'] = 10;
        values['L'] = 50;
        values['C'] = 100; 
        values['D'] = 500;
        values['M'] = 1000;

        int ans = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (i + 1 < n && values[s[i]] < values[s[i + 1]]) {
                ans += values[s[i + 1]] - values[s[i]];
                i++; // skip next since it's already processed
            } else {
                ans += values[s[i]];
            }
        }

        return ans;
    }
};

// Example usage
int main() {
    Solution sol;
    cout << sol.romanToInt("III") << endl;    // Output: 3
    cout << sol.romanToInt("IV") << endl;     // Output: 4
    cout << sol.romanToInt("IX") << endl;     // Output: 9
    cout << sol.romanToInt("LVIII") << endl;  // Output: 58
    cout << sol.romanToInt("MCMXCIV") << endl; // Output: 1994
    return 0;
}
