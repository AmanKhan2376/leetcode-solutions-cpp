/*
Leetcode Problem 20: Valid Parentheses
--------------------------------------
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

An input string is valid if:
1. Open brackets are closed by the same type of brackets.
2. Open brackets are closed in the correct order.
3. Every closing bracket has a corresponding open bracket of the same type.

Approach (Stack-based Matching):
--------------------------------
- Traverse the string character by character.
- Push opening brackets ('(', '{', '[') onto a stack.
- For closing brackets:
  - If the stack is empty, return false (no matching opening).
  - Check if the top of the stack is the corresponding opening bracket.
  - If not, return false.
  - Otherwise, pop the stack.
- At the end, the stack must be empty for the string to be valid.

Time Complexity:  O(n)  - Traverse string once
Space Complexity: O(n)  - Stack to store opening brackets
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) {
                    return false;
                }
                if ((c == ')' && st.top() != '(') ||
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '[')) {
                        return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};

// Example usage
int main() {
    string s = "()[]{}";
    cout << (Solution().isValid(s) ? "Valid" : "Invalid") << endl;

    s = "(]";
    cout << (Solution().isValid(s) ? "Valid" : "Invalid") << endl;

    return 0;
}
