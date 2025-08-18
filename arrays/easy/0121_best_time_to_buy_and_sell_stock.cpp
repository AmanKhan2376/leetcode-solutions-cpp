/*
LeetCode Problem 121: Best Time to Buy and Sell Stock
-----------------------------------------------------
You are given an array prices where prices[i] is the price of a given stock on the i-th day. 
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day 
in the future to sell that stock. Return the maximum profit you can achieve.

Approach (One Pass - O(n) Time, O(1) Space):
--------------------------------------------
- Maintain minPrice initialized to the first day's price.
- Initialize maxProfit = 0.
- Iterate through prices from the second day:
  - Update minPrice with the minimum of current minPrice and prices[i].
  - Update maxProfit with the maximum of current maxProfit and (prices[i] - minPrice).
- Return maxProfit.

Time Complexity:  O(n)  - Single pass through prices
Space Complexity: O(1)  - Constant extra space
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrice = prices[0], maxProfit = 0;
        for(int i = 1; i < n; i ++) {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, (prices[i] - minPrice));
        }
        return maxProfit;
    }
};

// Example usage
int main() {
    vector<int> prices = {7,1,5,3,6,4};
    int result = Solution().maxProfit(prices);

    cout << "Maximum profit: " << result << endl;

    return 0;
}
