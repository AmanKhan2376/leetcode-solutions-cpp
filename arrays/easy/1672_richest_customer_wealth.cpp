/*
Leetcode Problem 1672: Richest Customer Wealth
---------------------------------------------
You are given an m x n integer grid accounts where accounts[i][j] is the amount of money 
the i-th customer has in the j-th bank. Return the wealth that the richest customer has.

Approach:
---------
- Iterate over each customer (row in accounts).
- Calculate the sum of money across all banks for that customer.
- Keep track of the maximum sum found so far.
- Return the maximum wealth after checking all customers.

Time Complexity:  O(m * n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int richest = 0;
        for (int i = 0; i < accounts.size(); i++) {
            int sum = 0;
            for (int j = 0; j < accounts[i].size(); j++) {
                sum += accounts[i][j];
            }
            richest = max(richest, sum);
        }
        return richest;
    }
};

// Example usage
int main() {
    vector<vector<int>> accounts = {{1, 2, 3}, {3, 2, 1}};
    int result = Solution().maximumWealth(accounts);

    cout << "Richest Customer Wealth: " << result << endl;  // Output: 6

    return 0;
}
