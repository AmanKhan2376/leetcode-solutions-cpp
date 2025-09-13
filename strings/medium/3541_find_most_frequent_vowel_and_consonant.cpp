/*
Leetcode Problem 3541: Find Most Frequent Vowel and Consonant
-------------------------------------------------------------
You are given a string s. You need to find the maximum possible sum of frequencies of 
two characters such that:
- One character is a vowel.
- The other character is a consonant.

Approach (Hash Map + Frequency Counting):
-----------------------------------------
- Count the frequency of each character in the string using unordered_map.
- Track the maximum frequency among vowels and among consonants.
- The answer is maxVowel + maxConsonant.

Time Complexity:  O(n)   (single pass over string + hash map iteration)
Space Complexity: O(1)   (at most 26 characters stored)
*/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> freq;

        // Count frequencies of each character
        for (char c : s) {
            freq[c]++;
        }

        string vowels = "aeiou";
        int maxVowel = 0;
        int maxConsonant = 0;

        // Find max vowel and consonant frequency
        for (auto& p : freq) {
            if (vowels.find(p.first) != string::npos) {
                maxVowel = max(maxVowel, p.second);
            } else {
                maxConsonant = max(maxConsonant, p.second);
            }
        }

        return maxVowel + maxConsonant;
    }
};

// Example usage
int main() {
    string s = "leetcode";
    Solution sol;
    int result = sol.maxFreqSum(s);

    cout << "Max frequency sum (vowel + consonant): " << result << endl;

    return 0;
}
