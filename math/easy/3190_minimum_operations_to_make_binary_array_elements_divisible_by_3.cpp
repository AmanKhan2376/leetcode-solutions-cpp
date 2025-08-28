/*
Leetcode Problem 3190: Minimum Operations to Make Binary Array Elements Divisible by 3
--------------------------------------------------------------------------------------
You are given an integer array nums. 
In one operation, you can change any number to make it divisible by 3.
Return the minimum number of operations required to make every number in nums divisible by 3.

Approach (Direct Count of Non-divisible Elements):
--------------------------------------------------
- Traverse through the array.
- For each element, check if it is divisible by 3.
- If not divisible, increment the operations counter.
- The final count gives the minimum operations needed.

Time Complexity:  O(n)  - Single pass through nums
Space Complexity: O(1)  - Only a counter variable
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;
        for (int num : nums) {
            if (num % 3 != 0) {
                operations++;
            }
        }
        return operations;
    }
};

// Example usage
int main() {
    vector<int> nums = {1, 2, 3, 4};
    cout << "Minimum Operations: " << Solution().minimumOperations(nums) << endl;

    nums = {3, 6, 9};
    cout << "Minimum Operations: " << Solution().minimumOperations(nums) << endl;

    return 0;
}
