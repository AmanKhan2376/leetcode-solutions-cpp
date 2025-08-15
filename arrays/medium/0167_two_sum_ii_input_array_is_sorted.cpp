/*
Leetcode Problem 167: Two Sum II - Input Array Is Sorted
--------------------------------------------------------
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, 
find two numbers such that they add up to a specific target number. Return the indices of the two numbers 
as an integer array [index1, index2] of length 2.

Approach (Two Pointers - O(n) Time, O(1) Space):
-------------------------------------------------
- Initialize two pointers: start at 0, end at n-1.
- While start < end:
    - If numbers[start] + numbers[end] equals target, return their 1-based indices.
    - If sum > target, decrement end.
    - If sum < target, increment start.
- Return empty array if no solution exists (though problem guarantees one solution).

Time Complexity:  O(n)  - Single pass through the array
Space Complexity: O(1)  - Constant extra space

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0, end = numbers.size() - 1;
        while (start < end) {
            if (numbers[start] + numbers[end] == target) 
                return {(start + 1), (end + 1)};
            else if (numbers[start] + numbers[end] > target) 
                end--;
            else 
                start++;
        }
        return {};
    }
};

// Example usage
int main() {
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = Solution().twoSum(numbers, target);

    cout << "Indices: ";
    for (int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
