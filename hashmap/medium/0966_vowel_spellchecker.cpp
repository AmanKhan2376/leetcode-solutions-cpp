/*
LeetCode Problem 966: Vowel Spellchecker
----------------------------------------
Given a wordlist and a list of queries, implement a spellchecker that matches queries 
to words in the wordlist using the following priority rules:

1. Exact match → return the exact word.
2. Case-insensitive match → if a word in the wordlist matches ignoring case, 
   return the first such word.
3. Vowel-error match → if a word matches when all vowels are replaced with '*', 
   return the first such word.
4. If no match → return "".

Approach:
---------
- Preprocess wordlist:
  * Store all words in an exact set.
  * Build a lowercase → word map (for case-insensitive).
  * Build a lowercase-with-vowels-replaced → word map (for vowel-error).
- For each query:
  * Check in order: exact → case-insensitive → vowel-error.
- Return results.

Time Complexity:  O(N + Q * L)  
   N = wordlist size, Q = queries size, L = avg word length  
Space Complexity: O(N * L)
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    unordered_set<string> exactSet;
    unordered_map<string, string> caseMap;
    unordered_map<string, string> vowelMap;

    // Convert to lowercase
    string toLower(const string& s) {
        string temp = s;
        for (char& c : temp) c = tolower(c);
        return temp;
    }

    // Replace vowels with '*'
    string replaceVowel(const string& s) {
        string temp = s;
        static const string vowels = "aeiou";
        for (char& c : temp) {
            if (vowels.find(c) != string::npos) {
                c = '*';
            }
        }
        return temp;
    }

    // Check match priority: exact → case-insensitive → vowel-error
    string checkForMatch(const string& s) {
        if (exactSet.count(s)) return s;

        string lower = toLower(s);
        if (caseMap.count(lower)) return caseMap[lower];

        string vowelForm = replaceVowel(lower);
        if (vowelMap.count(vowelForm)) return vowelMap[vowelForm];

        return "";
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> ans;

        // Preprocess wordlist
        for (const string& word : wordlist) {
            exactSet.insert(word);

            string lower = toLower(word);
            if (!caseMap.count(lower)) caseMap[lower] = word;

            string vowelForm = replaceVowel(lower);
            if (!vowelMap.count(vowelForm)) vowelMap[vowelForm] = word;
        }

        // Process queries
        for (const string& q : queries) {
            ans.push_back(checkForMatch(q));
        }

        return ans;
    }
};

// Example usage
int main() {
    vector<string> wordlist = {"KiTe", "kite", "hare", "Hare"};
    vector<string> queries = {"kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"};

    Solution sol;
    vector<string> result = sol.spellchecker(wordlist, queries);

    cout << "Spellchecker results: ";
    for (string& res : result) cout << res << " ";
    cout << endl;
    return 0;
}
