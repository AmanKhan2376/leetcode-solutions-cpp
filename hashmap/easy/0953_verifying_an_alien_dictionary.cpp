/*
Leetcode Problem 953: Verifying an Alien Dictionary
---------------------------------------------------
In an alien language, surprisingly, they also use English lowercase letters, 
but possibly in a different order. The order of the alphabet is given by a string order.

Given an array of words, return true if and only if the words are sorted lexicographically 
according to the given alien dictionary.

Approach (Custom Ordering with Hash Map):
-----------------------------------------
- Build a hash map `dictionary` that maps each character to its rank in the alien order.
- Iterate through consecutive word pairs (s1, s2):
    - Compare characters one by one until they differ or one ends.
    - If s1 is a prefix of s2 but longer → not sorted.
    - If differing characters exist and dictionary[s1[j]] > dictionary[s2[j]] → not sorted.
- If no violations are found, return true.

Time Complexity:  O(n * m)  
    - n = number of words, m = average word length.
Space Complexity: O(1)  
    - Hash map of fixed alphabet size (26).
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> dictionary;

        // Map alien order
        for (int i = 0; i < order.length(); i++) {
            dictionary[order[i]] = i;
        }

        // Compare adjacent words
        for (int i = 1; i < words.size(); i++) {
            string s1 = words[i - 1];
            string s2 = words[i];
            int j = 0;

            // Compare character by character
            while (j < min(s1.length(), s2.length()) && s1[j] == s2[j]) {
                j++;
            }

            // Case 1: prefix conflict
            if (j == s2.length() && s1.length() > s2.length()) return false;

            // Case 2: differing characters but wrong order
            if (j < s1.length() && j < s2.length() && dictionary[s1[j]] > dictionary[s2[j]]) {
                return false;
            }
        }

        return true;
    }
};

// Example usage
int main() {
    vector<string> words = {"hello", "leetcode"};
    string order = "hlabcdefgijkmnopqrstuvwxyz";
    Solution sol;
    bool result = sol.isAlienSorted(words, order);

    cout << "Are words sorted in alien dictionary? " << (result ? "true" : "false") << endl;

    return 0;
}
