/*
Leetcode Problem 14: Longest Common Prefix
------------------------------------------
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Approach (Iterative Prefix Reduction):
--------------------------------------
- Start with the first string as the initial prefix.
- Compare it with each string in the array.
- Reduce the prefix length until it matches the current string’s prefix.
- Continue until all strings are processed.
- Return the final prefix.

Time Complexity:  O(n * m) 
   - n = number of strings
   - m = length of the smallest string
Space Complexity: O(1) 
   - Only uses variables, no extra data structures
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (strs.empty()) return "";
        string ans;
        string prefix = strs[0];
        for (int i = 1; i < n; i++) {
            ans = "";
            int minLength = min(prefix.length(), strs[i].length());
            string s = strs[i];
            for (int j = 0; j < minLength; j++) {
                if (prefix[j] == s[j]) {
                    ans += s[j];
                } else {
                    break;
                }
            }
            prefix = ans;
        }
        return prefix;
    }
};

// Example usage
int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << Solution().longestCommonPrefix(strs) << endl;
    return 0;
}
