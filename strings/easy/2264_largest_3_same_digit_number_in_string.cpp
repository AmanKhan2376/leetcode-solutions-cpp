/*
Leetcode Problem 2264: Largest 3-Same-Digit Number in String
------------------------------------------------------------
You are given a string num representing a large integer.  
A "good integer" is a substring of num of length 3 that consists of the same digit repeated 3 times.

Return the largest good integer as a string, or an empty string "" if no such substring exists.

Approach (O(n) Time - Sliding Window Check):
--------------------------------------------
- Iterate through the string from index 0 to n-3.
- At each index, check if the next 3 characters are equal.
- If they are, compare this substring to the current best answer and keep the larger one.
- Return the best found substring at the end.

This is an O(n) time, O(1) extra space solution.

Time Complexity:  O(n)  - Single pass through the string
Space Complexity: O(1)  - Constant extra memory usage

*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        for (int i = 0; i < (int)num.size() - 2; i++) {
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
                string cur = num.substr(i, 3);
                if (cur > ans) ans = cur;
            }
        }
        return ans;
    }
};

// Example usage
int main() {
    string num = "6777133339";
    cout << "Largest good integer: " << Solution().largestGoodInteger(num) << endl;
    return 0;
}
