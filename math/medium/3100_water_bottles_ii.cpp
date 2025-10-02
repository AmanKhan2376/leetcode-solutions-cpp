/*
LeetCode 3100: Water Bottles II
-------------------------------
You are given two integers numBottles and numExchange.

- numBottles represents the number of full water bottles that you initially have.  
- In one operation, you can perform one of the following operations:
  1. Drink any number of full water bottles turning them into empty bottles.
  2. Exchange numExchange empty bottles for one full water bottle. Then, increase numExchange by one.

Note:
- You cannot exchange multiple batches of empty bottles for the same value of numExchange.  
  (For example, if numBottles == 3 and numExchange == 1, you cannot exchange 3 empty bottles for 3 full bottles.)

Return the maximum number of water bottles you can drink.

Approach:
---------
- Initialize `bottlesDrunk` to track total bottles consumed.
- Initialize `emptyBottles` to track empty bottles available for exchange.
- While there are bottles to drink:
  1. Drink all current full bottles and add them to emptyBottles.
  2. Exchange empty bottles as long as emptyBottles >= numExchange.
  3. Increment numExchange after each exchange (as per problem-specific rule if applicable).
- Repeat until no bottles can be exchanged.

Time Complexity: O(n) in the worst case 
Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int bottlesDrunk = 0;
        int emptyBottles = 0;

        while (numBottles != 0) {
            bottlesDrunk += numBottles;
            emptyBottles += numBottles;
            numBottles = 0;

            while (emptyBottles >= numExchange) {
                numBottles++;
                emptyBottles -= numExchange;
                numExchange++;
            }
        }

        return bottlesDrunk;
    }
};

// Example usage
int main() {
    Solution sol;
    cout << sol.maxBottlesDrunk(9, 3) << endl; // Example output
    return 0;
}
