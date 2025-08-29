/*
Leetcode Problem 3: Longest Substring Without Repeating Characters
-----------------------------------------------------------------
Given a string s, find the length of the longest substring without repeating characters.

Approach:
---------
- Use a sliding window with two pointers: left and right.
- Keep an array `lastIndex` of size 256 to store the last seen index of each character.
- Iterate through the string with the `right` pointer:
    - If the current character was seen within the current window (lastIndex[c] >= left), move `left` to lastIndex[c] + 1.
    - Update lastIndex[c] = right.
    - Update maxLen = max(maxLen, right - left + 1).
- Return maxLen after iteration.

Time Complexity:  O(n)   (each character visited once)
Space Complexity: O(1)   (fixed size array of 256)
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> lastIndex(256, -1); 
        int maxLen = 0;
        int left = 0; 

        for (int right = 0; right < n; right++) {
            char c = s[right];
            if (lastIndex[c] >= left) {
                left = lastIndex[c] + 1;
            }
            lastIndex[c] = right; 
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

// Example usage
int main() {
    string s = "abcabcbb";
    int result = Solution().lengthOfLongestSubstring(s);
    cout << "Length of longest substring without repeating characters: " << result << endl;
    return 0;
}
