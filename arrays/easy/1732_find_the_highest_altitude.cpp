/*
Leetcode Problem 1732: Find the Highest Altitude
------------------------------------------------
There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes.  
The biker starts at point 0 with altitude equal to 0.

You are given an integer array gain of length n where gain[i] is the net gain in altitude 
between points i and i + 1 for all (0 <= i < n).  
Return the highest altitude of a point.

Approach:
---------
- Start with altitude 0.
- Traverse the array gain:
    - Add each element to a running sum (current altitude).
    - Track the maximum altitude reached so far.
- Return the maximum altitude.

Time Complexity:  O(n)   (single traversal of gain array)
Space Complexity: O(1)   (constant extra space)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxSum = 0, currSum = 0;
        for (int alt : gain) {
            currSum += alt;
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};

// Example usage
int main() {
    vector<int> gain = {-5, 1, 5, 0, -7};
    Solution sol;
    int result = sol.largestAltitude(gain);
    cout << "Highest altitude: " << result << endl;
    return 0;
}
