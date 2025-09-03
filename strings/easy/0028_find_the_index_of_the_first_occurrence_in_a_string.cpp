/*
Leetcode Problem 28: Find the Index of the First Occurrence in a String
----------------------------------------------------------------------
Given two strings needle and haystack, return the index of the first occurrence 
of needle in haystack, or -1 if needle is not part of haystack.

Approach:
---------
- If needle is longer than haystack, return -1 immediately.
- Iterate over haystack from index 0 to n1 - n2:
    - If current character matches needle[0], start checking substring.
    - Compare characters of haystack and needle one by one.
    - If all characters match, return the starting index.
    - Otherwise, continue searching.
- Return -1 if no match is found.

Time Complexity:  O(n1 * n2) in the worst case
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans = -1;
        int n1 = haystack.size();
        int n2 = needle.size();

        if (n2 > n1) return -1;

        for (int i = 0; i <= n1 - n2; i++) {
            if (haystack[i] == needle[0]) {
                ans = i;
                int idx1 = i, idx2 = 0;
                while (idx2 < needle.size()) {
                    if (haystack[idx1] != needle[idx2]) {
                        ans = -1;
                        break;
                    }
                    idx1++;
                    idx2++;
                }
                if (ans != -1) return ans;
            }
        }
        return ans;
    }
};

// Example usage
int main() {
    string haystack = "sadbutsad";
    string needle = "sad";
    Solution sol;
    int result = sol.strStr(haystack, needle);
    cout << "Index of first occurrence: " << result << endl;
    return 0;
}
