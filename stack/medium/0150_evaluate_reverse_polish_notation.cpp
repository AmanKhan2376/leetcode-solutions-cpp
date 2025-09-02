/*
Leetcode Problem 150: Evaluate Reverse Polish Notation
-----------------------------------------------------
Given an array of strings tokens representing an arithmetic expression in Reverse Polish Notation, 
evaluate the expression and return the result. Valid operators are +, -, *, and /.

Approach:
---------
- Use a stack to store intermediate numbers.
- Iterate through the tokens:
    - If token is an operator, pop the top two numbers, apply the operator, and push the result back.
    - If token is a number, convert it to int and push onto the stack.
- After processing all tokens, the stack top contains the final result.

Time Complexity:  O(n)   (each token processed once)
Space Complexity: O(n)   (stack may hold all numbers in worst case)
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> s;
        for (int i = 0; i < n; i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int a2 = s.top(); s.pop();
                int a1 = s.top(); s.pop();
                if (tokens[i] == "+") s.push(a1 + a2);
                if (tokens[i] == "-") s.push(a1 - a2);
                if (tokens[i] == "*") s.push(a1 * a2);
                if (tokens[i] == "/") s.push(a1 / a2);
            } else {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};

// Example usage
int main() {
    vector<string> tokens = {"2","1","+","3","*"};
    Solution sol;
    int result = sol.evalRPN(tokens);
    cout << "Result of RPN expression: " << result << endl;
    return 0;
}
