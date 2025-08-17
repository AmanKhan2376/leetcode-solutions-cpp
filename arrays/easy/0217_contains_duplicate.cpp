/*
Leetcode Problem 217: Contains Duplicate
----------------------------------------
Given an integer array nums, return true if any value appears at least twice in the array, 
and false if every element is distinct.

Approach (Hash Set - O(n) Time, O(n) Space):
--------------------------------------------
- Initialize an unordered_set to store seen elements.
- Iterate through nums:
    - If the current number is already in the set, return true.
    - Otherwise, insert it into the set.
- Return false if no duplicates are found.

Time Complexity:  O(n)  - Single pass through the array
Space Complexity: O(n)  - Hash set storing up to n elements

*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num)) return true;
            seen.insert(num);
        }
        return false;
    }
};

// Example usage
int main() {
    vector<int> nums = {1,2,3,4,1};
    bool result = Solution().containsDuplicate(nums);

    cout << "Contains duplicate: " << (result ? "true" : "false") << endl;

    return 0;
}
