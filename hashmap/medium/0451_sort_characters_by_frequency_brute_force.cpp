/*
LeetCode Problem 451: Sort Characters By Frequency
--------------------------------------------------
Given a string s, sort it in decreasing order based on the frequency 
of the characters. The frequency of a character is the number of 
times it appears in the string.

Approach:
---------
- Count character frequencies using unordered_map.
- Track maximum frequency to know the range of buckets.
- Iterate from max frequency down to 1:
  * For each character with that frequency, append it 'freq' times to result.
- Return the constructed string.

Time Complexity:  O(n * k) in worst case (n = length of string, k = unique chars ≤ 26/62)
Space Complexity: O(k), for frequency map
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        string ans;

        int n = s.length();
        int maxFreq = 0;

        // Count frequencies
        for (int i = 0; i < n; i++) {
            freq[s[i]]++;
            maxFreq = max(maxFreq, freq[s[i]]);
        }

        // Append chars by decreasing frequency
        for (int i = maxFreq; i > 0; i--) {
            for (auto it : freq) {
                if (it.second == i) {
                    ans.append(i, it.first);
                }
            }
        }

        return ans;
    }
};

// Example usage
int main() {
    Solution sol;
    string s = "tree";
    cout << sol.frequencySort(s) << endl;  // Output: "eert" or "eetr"
    return 0;
}
