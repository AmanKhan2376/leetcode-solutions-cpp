/*
LeetCode Problem 1935: Maximum Number of Words You Can Type
-----------------------------------------------------------
You are given a string 'text' and a string 'brokenLetters' that contains distinct characters. 
A word cannot be typed if it contains any broken letter.

Return the number of words you can type fully.

Approach:
---------
- Store broken letters in an unordered_set for O(1) lookup.
- Use stringstream to split text into words.
- For each word, check if it contains any broken letter:
  * If yes → skip
  * If no → count++
- Return total count.

Time Complexity:  O(N)   where N = length of text
Space Complexity: O(K)   where K = number of broken letters
*/

#include <iostream>
#include <sstream>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken;
        for (char c : brokenLetters) {
            broken.insert(c);
        }

        stringstream ss(text);
        int ans = 0;
        string word;

        while (ss >> word) {
            bool found = false;
            for (char c : word) {
                if (broken.find(c) != broken.end()) {
                    found = true;
                    break;
                }
            }
            if (!found) ans++;
        }

        return ans;
    }
};

// Example usage
int main() {
    Solution sol;
    string text = "hello world leetcode";
    string broken = "ad";
    cout << sol.canBeTypedWords(text, broken) << endl; // Output: 1
    return 0;
}
