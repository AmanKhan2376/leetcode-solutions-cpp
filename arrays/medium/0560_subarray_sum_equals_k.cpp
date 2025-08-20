/*
LeetCode Problem 560: Subarray Sum Equals K
-------------------------------------------
Given an integer array nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

Approach (Prefix Sum + Hash Map - O(n) Time, O(n) Space):
---------------------------------------------------------
- Maintain a running prefix sum and a hash map to store counts of prefix sums.
- Initialize map with {0:1} to handle subarrays starting at index 0.
- For each element in nums:
    - Add it to prefixSum.
    - If (prefixSum - k) exists in map, increment count by map[prefixSum - k].
    - Increment map[prefixSum] by 1.
- Return count as the total number of subarrays.

Time Complexity:  O(n)  - Single pass through nums
Space Complexity: O(n)  - Hash map stores prefix sums

*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int prefixSum = 0;
        unordered_map<int, int> m;
        m[0] = 1; 

        for (int num : nums) {
            prefixSum += num;

            if (m.find(prefixSum - k) != m.end()) {
                count += m[prefixSum - k];
            }

            m[prefixSum]++;
        }

        return count;
    }
};

// Example usage
int main() {
    vector<int> nums = {1,1,1};
    int k = 2;
    int result = Solution().subarraySum(nums, k);

    cout << "Number of subarrays summing to " << k << ": " << result << endl;

    return 0;
}
