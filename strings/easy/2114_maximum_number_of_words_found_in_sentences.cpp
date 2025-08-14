/*
Leetcode Problem 2114: Maximum Number of Words Found in Sentences
-----------------------------------------------------------------
Given a list of sentences, where each sentence is a string consisting of words separated by single spaces, 
return the maximum number of words found in any single sentence.

Approach (O(n * m) Time - Direct Counting):
-------------------------------------------
- For each sentence in the input vector:
    - Initialize a counter for words starting at 1.
    - Iterate through each character in the sentence.
    - Increment the counter when a space is found.
- Track the maximum word count across all sentences.
- Return the maximum.

Here, n = number of sentences and m = average length of a sentence.

Time Complexity:  O(n * m) - Each character of each sentence is processed once.
Space Complexity: O(1)     - Only a few integer variables used.

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0;
        for (string &str : sentences) {
            int curCount = 1;
            for (char ch : str) {
                if (ch == ' ') {
                    curCount++;
                }
            }
            ans = max(ans, curCount);
        }
        return ans;
    }
};

// Example usage
int main() {
    vector<string> sentences = {
        "alice and bob love leetcode",
        "i think so too",
        "this is great thanks very much"
    };
    int result = Solution().mostWordsFound(sentences);

    cout << "Maximum number of words: " << result << endl;

    return 0;
}
