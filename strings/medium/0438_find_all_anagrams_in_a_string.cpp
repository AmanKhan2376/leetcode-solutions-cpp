/*
Leetcode Problem 438: Find All Anagrams in a String
---------------------------------------------------
Given two strings s and p, return an array of all the start indices of p's anagrams in s. 
You may return the answer in any order.

Approach (Sliding Window + Frequency Counting):
-----------------------------------------------
- Use two frequency arrays of size 26 for lowercase letters: `pFreq` for p, `sFreq` for current window in s.
- Expand the window by moving right pointer `j`.
- Once window size exceeds length of p, shrink from the left by moving pointer `i` and updating `sFreq`.
- If `sFreq` matches `pFreq`, record starting index `i` as an anagram.
- Continue until the end of s.

Time Complexity:  O(n)   (single pass over s)
Space Complexity: O(26)  (fixed size frequency arrays)
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.length();
        int pLen = p.length();

        if (pLen > sLen) return {};

        vector<int> ans;
        vector<int> pFreq(26, 0), sFreq(26, 0);

        for (char c : p) {
            pFreq[c - 'a']++;
        }

        int i = 0;
        for (int j = 0; j < sLen; j++) {
            sFreq[s[j] - 'a']++;
            
            if (j - i + 1 > pLen) {
                sFreq[s[i] - 'a']--;
                i++;
            }

            if (j - i + 1 == pLen && sFreq == pFreq) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

// Example usage
int main() {
    string s = "cbaebabacd";
    string p = "abc";
    Solution sol;
    vector<int> result = sol.findAnagrams(s, p);

    cout << "Start indices of anagrams: ";
    for (int idx : result) cout << idx << " ";
    cout << endl;

    return 0;
}
