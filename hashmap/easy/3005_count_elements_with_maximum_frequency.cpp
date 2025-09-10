/*
Leetcode Problem 3005: Count Elements With Maximum Frequency
------------------------------------------------------------
You are given an array nums consisting of positive integers.

Return the total number of elements in nums such that their frequency 
is equal to the maximum frequency.

Approach (Hash Map Frequency Counting):
---------------------------------------
- Use an unordered_map to count the frequency of each number.
- Track the maximum frequency while building the map.
- Iterate over the map:
    - For each number whose frequency == max frequency, add that frequency to the answer.
- Return the total count.

Time Complexity:  O(n)   (two passes over nums + freq map)
Space Complexity: O(n)   (hash map to store frequencies)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0, count = 0;

        // Count frequencies and track max frequency
        for (int num : nums) {
            freq[num]++;
            maxFreq = max(maxFreq, freq[num]);
        }

        // Sum counts of elements that have max frequency
        for (auto& [num, f] : freq) {
            if (f == maxFreq) {
                count += f;
            }
        }

        return count;
    }
};

// Example usage
int main() {
    vector<int> nums = {1, 2, 2, 3, 1, 4};
    Solution sol;
    int result = sol.maxFrequencyElements(nums);

    cout << "Count of elements with maximum frequency: " << result << endl;

    return 0;
}
