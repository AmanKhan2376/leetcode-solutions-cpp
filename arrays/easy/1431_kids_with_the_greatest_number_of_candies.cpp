/*
Leetcode Problem 1431: Kids With the Greatest Number of Candies
----------------------------------------------------------------
Given the array candies and an integer extraCandies, return a boolean array result of the same length 
where result[i] is true if, after giving the i-th kid all extraCandies, they have the greatest number of candies 
among all kids, otherwise false.

Approach (Greedy - O(n) Time, O(n) Space):
-------------------------------------------
- Find the maximum number of candies any kid currently has.
- For each kid, check if candies[i] + extraCandies >= maximum.
- Store the result in a boolean vector.

Time Complexity:  O(n)  - Single pass to find max and single pass to build result
Space Complexity: O(n)  - Boolean vector result of size n

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int greatest = *max_element(candies.begin(), candies.end());
        vector<bool> result;
        result.reserve(candies.size());
        
        for (int c : candies)
            result.push_back(c + extraCandies >= greatest);
        
        return result;
    }
};

// Example usage
int main() {
    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;
    vector<bool> result = Solution().kidsWithCandies(candies, extraCandies);

    cout << "Result: ";
    for (bool val : result) cout << val << " ";
    cout << endl;

    return 0;
}
