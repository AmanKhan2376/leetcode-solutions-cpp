/*
Leetcode Problem 122: Best Time to Buy and Sell Stock II
-------------------------------------------------------
You are given an array prices where prices[i] is the price of a given stock on the i-th day.

You want to maximize your profit by choosing a **sequence of buy and sell transactions**.  
You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Approach (Greedy):
-----------------
- Initialize total profit to 0.
- Iterate through prices from day 1 to n-1:
    - If price[i] > price[i-1], buy at day i-1 and sell at day i (add price difference to profit).
- This works because summing all positive differences is equivalent to performing all profitable transactions.

Time Complexity:  O(n)   (single pass)
Space Complexity: O(1)   (constant extra space)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            } 
        }
        return profit;
    }
};

// Example usage
int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution sol;
    int result = sol.maxProfit(prices);

    cout << "Maximum profit: " << result << endl;

    return 0;
}
