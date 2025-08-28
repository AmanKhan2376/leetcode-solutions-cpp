/*
Leetcode Problem 2798: Number of Employees Who Met the Target
-------------------------------------------------------------
You are given a 0-indexed array hours of length n and a non-negative integer target.

Each element in hours represents the number of hours an employee worked.  
Return the number of employees who worked at least target hours.

Approach:
---------
- Initialize a counter.
- Iterate through the hours array.
- If an employee’s worked hours >= target, increment the counter.
- Return the final count.

Time Complexity:  O(n)   (single pass through the array)
Space Complexity: O(1)   (constant extra space)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int numEmp = 0;
        for (int i = 0; i < hours.size(); i++) {
            if (hours[i] >= target) numEmp++;
        }
        return numEmp;
    }
};

// Example usage
int main() {
    vector<int> hours = {0, 1, 2, 3, 4};
    int target = 2;

    Solution sol;
    int result = sol.numberOfEmployeesWhoMetTarget(hours, target);

    cout << "Number of employees who met target: " << result << endl;

    return 0;
}
