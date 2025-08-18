/*
LeetCode Problem 414: Third Maximum Number
------------------------------------------
Given an integer array nums, return the third distinct maximum number in this array. 
If the third maximum does not exist, return the maximum number.

Approach (Three Variables - O(n) Time, O(1) Space):
----------------------------------------------------
- Maintain three variables: first, second, and third initialized to LONG_MIN.
- Iterate through nums:
    - Skip numbers equal to any of first, second, or third (to handle duplicates).
    - Update first, second, third based on comparisons with current number.
- Return third if it exists; otherwise return first.

Time Complexity:  O(n)  - Single pass through the array
Space Complexity: O(1)  - Constant extra space
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
        for(int num: nums){
            if(num == first || num == second || num == third) continue;
            if (num > first) {
                third = second;  
                second = first;  
                first = num;     
            }
            else if (num > second) {
                third = second;  
                second = num;    
            }
            else if (num > third) {
                third = num;     
            }
        }
        return (third == LONG_MIN) ? first : third;    
    }
};

// Example usage
int main() {
    vector<int> nums = {3, 2, 1};
    int result = Solution().thirdMax(nums);

    cout << "Third maximum number: " << result << endl;

    return 0;
}
