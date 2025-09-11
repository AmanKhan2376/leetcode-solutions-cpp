/*
Leetcode Problem 2785: Sort Vowels in a String
----------------------------------------------
Given a string s, sort only the vowels in the string and return it.  
The consonants should remain in their original positions.

Approach:
---------
- Extract all vowels from the string into a temporary container.
- Sort the vowels in ascending order.
- Iterate over the string again, replacing vowels in order with the sorted ones.
- Consonants remain untouched.

Time Complexity:  O(n log n)   (sorting vowels)
Space Complexity: O(n)         (storing vowels separately)
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        string vowels = "";
        unordered_set<char> vowelsSet = {'a','e','i','o','u','A','E','I','O','U'};

        // Collect vowels
        for (char c : s) {
            if (vowelsSet.find(c) != vowelsSet.end()) {
                vowels += c;
            }
        }

        // Sort vowels
        sort(vowels.begin(), vowels.end());
        int vIdx = 0;

        // Replace vowels in string with sorted ones
        for (int i = 0; i < s.length(); i++) {
            if (vowelsSet.find(s[i]) != vowelsSet.end()) {
                s[i] = vowels[vIdx++];
            }
        }

        return s;
    }
};

// Example usage
int main() {
    string s = "lEetcOde";
    Solution sol;
    string result = sol.sortVowels(s);

    cout << "Result: " << result << endl; // Expected: "lEOtcede"

    return 0;
}
