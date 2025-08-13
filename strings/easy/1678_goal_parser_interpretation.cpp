/*
LeetCode Problem 1678: Goal Parser Interpretation
-------------------------------------------------
You own a Goal Parser that can interpret a string command. The command consists of:
- "G" → add "G" to the output
- "()" → add "o" to the output
- "(al)" → add "al" to the output

Given a string command, return the interpreted string.

Approach:
---------
- Initialize an empty string `ans`.
- Iterate over each character in `command`.
- If character is 'G', append 'G'.
- If substring is "()", append 'o' and skip next character.
- If substring is "(al)", append "al" and skip next three characters.
- Return the result string.

Time Complexity:  O(n)
Space Complexity: O(n)
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string interpret(string command) {
        string ans;
        int n = command.length();
        for (int i = 0; i < n; i++) {
            if (command[i] == 'G') {
                ans += 'G';
            } else if (i + 1 < n && command[i] == '(' && command[i + 1] == ')') {
                ans += 'o';
                i += 1;
            } else if (i + 3 < n && command.substr(i, 4) == "(al)") {
                ans += "al";
                i += 3;
            }
        }
        return ans;
    }
};

// Example usage
int main() {
    string command = "G()(al)";
    Solution sol;
    cout << "Interpreted Command: " << sol.interpret(command) << endl;  // Output: "Goal"
    return 0;
}
