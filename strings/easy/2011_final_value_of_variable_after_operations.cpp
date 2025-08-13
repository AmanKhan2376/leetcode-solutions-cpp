/*
LeetCode Problem 2011: Final Value of Variable After Performing Operations
--------------------------------------------------------------------------
There is a programming language with only four operations for a variable X:

    ++X and X++ increase the value of the variable X by 1.
    --X and X-- decrease the value of the variable X by 1.

Initially, the value of X is 0.

Given an array of strings operations containing a list of operations, return the final value of X after performing all the operations.

Approach:
---------
- Initialize X to 0.
- Iterate over the operations list.
- If the middle character (index 1) of the string is '+', increment X.
- Otherwise, decrement X.
- This works because all operations have exactly three characters and the middle one always determines whether it’s increment or decrement.

Time Complexity:  O(n) 
Space Complexity: O(1)

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (string &op : operations) {
            if (op[1] == '+') x++;
            else x--;
        }
        return x;
    }
};

// Example usage
int main() {
    vector<string> operations = {"--X", "X++", "X++"};
    Solution sol;
    cout << "Final Value: " << sol.finalValueAfterOperations(operations) << endl;
    return 0;
}
