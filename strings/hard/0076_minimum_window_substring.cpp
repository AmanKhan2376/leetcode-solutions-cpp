/*
LeetCode Problem 76: Minimum Window Substring
---------------------------------------------
Given two strings s and t, return the minimum window substring of s 
such that every character in t (including duplicates) is included in the window. 
If no such substring exists, return an empty string.

Approach (Sliding Window + Frequency Count):
--------------------------------------------
- Use a frequency array `freq` of size 128 (ASCII).
- First, populate `freq` with counts of chars in t.
- Use two pointers (left, right) to expand/shrink the sliding window.
- Each time we include a char, decrement its freq. If it was > 0 before decrement, 
  we have matched one more required char.
- When `count == tLen`, we try shrinking from the left to minimize window size, 
  updating the answer whenever we find a smaller valid window.
- If no valid window is found, return "".

Time Complexity:  O(|s| + |t|)  
Space Complexity: O(128) ≈ O(1)
*/

#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128, 0);
        int left = 0, right = 0, minLen = INT_MAX, startIdx = -1, count = 0;
        int sLen = s.size(), tLen = t.size();

        for (char c : t) {
            freq[c]++;
        }

        while (right < sLen) {
            if (freq[s[right]] > 0) {
                count++;
            }
            freq[s[right]]--;

            while (count == tLen) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }
                freq[s[left]]++;
                if (freq[s[left]] > 0) count--;
                left++;
            }
            right++;
        }

        if (startIdx == -1) return "";
        return s.substr(startIdx, minLen);
    }
};

// Example usage
int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution sol;
    string result = sol.minWindow(s, t);
    cout << "Minimum window substring: " << result << endl;
    return 0;
}
