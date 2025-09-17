/*
LeetCode Problem 424: Longest Repeating Character Replacement
-------------------------------------------------------------
You are given a string s and an integer k. You can choose any 
character of the string and change it to any other uppercase 
English character. Perform at most k operations.

Return the length of the longest substring containing the same 
letter after performing the operations.

Approach:
---------
- Use sliding window with two pointers.
- Maintain a frequency array for characters in the current window.
- Track the maximum frequency of a single character (maxFreq).
- If the window size - maxFreq > k, shrink from the left.
- Update maxLen with the largest valid window.

Time Complexity:  O(n), where n = length of s  
Space Complexity: O(26) ≈ O(1)  
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, maxLen = 0, maxFreq = 0;
        vector<int> freq(26, 0);

        for (int r = 0; r < s.size(); r++) {
            freq[s[r] - 'A']++;
            maxFreq = max(maxFreq, freq[s[r] - 'A']);  // update only for new char

            // shrink window if more than k replacements needed
            while ((r - l + 1) - maxFreq > k) {
                freq[s[l] - 'A']--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};

// Example usage
int main() {
    Solution sol;
    string s = "AABABBA";
    int k = 1;
    cout << sol.characterReplacement(s, k) << endl; // Output: 4
    return 0;
}
