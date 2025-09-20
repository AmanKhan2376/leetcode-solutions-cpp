/*
Leetcode Problem 567: Permutation in String
-------------------------------------------
Given two strings s1 and s2, return true if s2 contains a permutation of s1, 
or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

Approach:
---------
- Use frequency arrays of size 26 (for lowercase English letters).
- Count the frequency of characters in s1.
- Use a sliding window of size s1.length() over s2:
    - Add the current character to the frequency array of the window.
    - If the window size exceeds s1 length, remove the leftmost character.
    - Compare frequency arrays of s1 and current window:
        - If equal, s2 contains a permutation of s1 → return true.
- If no match is found after scanning, return false.

Time Complexity:  O(n)   (where n = length of s2)
Space Complexity: O(1)   (fixed array size of 26)
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length()) {
            return false;
        }

        vector<int> freqS1(26, 0);
        vector<int> freqS2(26, 0);

        for (char c : s1) {
            freqS1[c - 'a']++;
        }

        int i = 0, j = 0, n = s2.length();

        while (j < n) {
            freqS2[s2[j] - 'a']++;
            j++;
            if (j > s1.length()) {
                freqS2[s2[i] - 'a']--;
                i++;
            }
            if (freqS1 == freqS2) return true;
        }

        return false;
    }
};

// Example usage
int main() {
    string s1 = "ab";
    string s2 = "eidbaooo";

    bool result = Solution().checkInclusion(s1, s2);

    cout << "Contains permutation: " << (result ? "true" : "false") << endl;

    return 0;
}
