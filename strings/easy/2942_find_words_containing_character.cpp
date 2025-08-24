/*
Leetcode Problem 2942: Find Words Containing Character
------------------------------------------------------
You are given an array of strings words and a character x. 
Return a list of indices representing the words that contain the character x.

Approach (Direct String Search):
--------------------------------
- Iterate over each word in the list.
- Use string.find(x) to check if the character exists in the word.
- If found, add the index to the result list.
- Return the final list of indices.

Time Complexity:  O(n * m) 
   - n = number of words
   - m = average length of each word
Space Complexity: O(k) 
   - k = number of indices stored in result
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for (int i = 0; i < words.size(); i++) {
            if (words[i].find(x) != string::npos) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// Example usage
int main() {
    vector<string> words = {"leet", "code", "chatgpt"};
    char x = 'e';
    vector<int> result = Solution().findWordsContaining(words, x);

    cout << "Indices: ";
    for (int idx : result) cout << idx << " ";
    cout << endl;

    return 0;
}
