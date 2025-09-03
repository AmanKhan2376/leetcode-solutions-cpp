/*
Leetcode Problem 345: Reverse Vowels of a String
------------------------------------------------
Given a string s, reverse only all the vowels in the string and return it.
The vowels are 'a', 'e', 'i', 'o', 'u' (both lowercase and uppercase).

Approach:
---------
- Use two pointers: one starting at the beginning (i), one at the end (j).
- Move i forward until it points to a vowel, and j backward until it points to a vowel.
- Swap the vowels at i and j.
- Continue until the two pointers meet.
- Return the modified string.

Time Complexity:  O(n)   (each character checked at most once)
Space Complexity: O(1)   (in-place swaps)
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    string reverseVowels(string s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (!isVowel(s[i])) { i++; continue; }
            if (!isVowel(s[j])) { j--; continue; }
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};

// Example usage
int main() {
    string s = "hello";
    Solution sol;
    string result = sol.reverseVowels(s);
    cout << "String after reversing vowels: " << result << endl;
    return 0;
}
