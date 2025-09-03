/*
Leetcode Problem 1422: Maximum Score After Splitting a String
-------------------------------------------------------------
Given a string s of zeros and ones, split the string into two non-empty substrings 
(left and right) such that the score is the number of zeros in the left substring 
plus the number of ones in the right substring.

Return the maximum score after splitting the string.

Approach:
---------
- First, count the total number of '1's (this will be the initial rightSum).
- Iterate through the string up to n-1 (ensuring both parts are non-empty):
    - If the current char is '0', increment leftSum.
    - If it is '1', decrement rightSum (as this '1' moves from right to left).
    - Compute current score = leftSum + rightSum.
    - Track the maximum score.
- Return the maximum score found.

Time Complexity:  O(n)   (single pass to count 1's + single pass to compute score)
Space Complexity: O(1)   (only counters used)
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int leftSum = 0, rightSum = 0, maxSum = 0;

        // Count total ones initially (all are in right substring)
        for (char ch : s) {
            if (ch == '1') {
                rightSum++;
            }
        }

        // Traverse and simulate splitting
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') leftSum++;
            else rightSum--;
            int currSum = leftSum + rightSum;
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};

// Example usage
int main() {
    string s = "011101";
    Solution sol;
    int result = sol.maxScore(s);
    cout << "Maximum score after splitting string: " << result << endl;
    return 0;
}
