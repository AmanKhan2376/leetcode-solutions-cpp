/*
LeetCode Problem 49: Group Anagrams
-----------------------------------
Given an array of strings strs, group the anagrams together. 
You can return the answer in any order.

Approach:
---------
- Use a hash map with key = sorted string, value = list of words.
- For each word:
  * Sort characters to form its canonical key.
  * Insert the original word into the map at that key.
- Collect all grouped anagrams from the hash map values.

Time Complexity:  O(N * K log K), 
    where N = number of words, K = max word length (due to sorting)
Space Complexity: O(N * K), for storing groups
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());  // canonical key
            map[key].push_back(s);
        }

        vector<vector<string>> ans;
        ans.reserve(map.size());
        for (auto& it : map) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

// Example usage
int main() {
    Solution sol;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result = sol.groupAnagrams(strs);

    for (auto& group : result) {
        cout << "[ ";
        for (auto& word : group) cout << word << " ";
        cout << "] ";
    }
    cout << endl;

    return 0;
}
