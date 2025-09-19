/*
Leetcode Problem 451: Sort Characters By Frequency
-------------------------------------------------
Given a string s, sort it in decreasing order based on the frequency of the characters.  
Return the sorted string. If multiple answers exist, return any of them.

Approach:
---------
- Use an unordered_map to count the frequency of each character.
- Create a "bucket" vector of vectors where index i contains characters appearing i times.
- Iterate the bucket from high to low frequency:
    - Append each character i times to the result string.
- This efficiently sorts characters by frequency.

Time Complexity:  O(n)   
Space Complexity: O(n)   
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        string ans;
        unordered_map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }

        vector<vector<char>> bucket(s.length() + 1);
        for (auto it : freq) {
            bucket[it.second].push_back(it.first);
        }

        for (int i = s.length(); i > 0; i--) {
            for (char c : bucket[i]) {
                ans.append(i, c);
            }
        }
        return ans;
    }
};

// Example usage
int main() {
    string s = "tree";

    string result = Solution().frequencySort(s);

    cout << "Sorted by frequency: " << result << endl;

    return 0;
}
