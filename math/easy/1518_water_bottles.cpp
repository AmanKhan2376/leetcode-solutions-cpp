/*
LeetCode 1518. Water Bottles
----------------------------
Problem Statement:
------------------
Given numBottles full water bottles, you can exchange numExchange empty bottles
for one full water bottle. The operation can be repeated until you cannot 
exchange any more bottles. Return the maximum number of water bottles you can drink.

Approach:
---------
- Start with `numBottles` full bottles.
- Keep track of the number of empty bottles.
- While you can still exchange:
  1. Calculate new full bottles from empty ones.
  2. Update answer count.
  3. Update empty bottles count.
- Continue until exchanges are no longer possible.

Time Complexity:  O(log(numBottles)) (each loop reduces empty bottles)
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int emptyBottles = numBottles;

        while (numBottles != 0) {
            numBottles = emptyBottles / numExchange;  // new full bottles
            emptyBottles %= numExchange;              // leftover empty bottles
            ans += numBottles;                        // drink new bottles
            emptyBottles += numBottles;               // add to empty count
        }

        return ans;
    }
};

// Example usage
int main() {
    Solution sol;
    cout << sol.numWaterBottles(9, 3) << endl;  // Output: 13
    cout << sol.numWaterBottles(15, 4) << endl; // Output: 19
    return 0;
}
