/*
Leetcode Problem 2053: Kth Distinct String in an Array
------------------------------------------------------
A distinct string is a string that appears exactly once in an array.

Given an array of strings arr, and an integer k, return the kth distinct string present in arr.  
If there are fewer than k distinct strings, return an empty string "".

Approach (Hash Map + Order Preservation):
-----------------------------------------
- Use an unordered_map to count the frequency of each string.
- Iterate over arr again (to preserve order):
    - For each string with frequency = 1, increment a counter.
    - When the counter reaches k, return that string.
- If no kth distinct string exists, return "".

Time Complexity:  O(n)   (two passes over arr)
Space Complexity: O(n)   (hash map to store frequencies)
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> freq;

        // Count frequencies
        for (string s : arr) {
            freq[s]++;
        }

        // Find kth distinct string
        int count = 0;
        for (string s : arr) {
            if (freq[s] == 1) {
                count++;
                if (count == k) return s;
            }
        }
        return "";
    }
};

// Example usage
int main() {
    vector<string> arr = {"d","b","c","b","c","a"};
    int k = 2;
    Solution sol;
    string result = sol.kthDistinct(arr, k);

    cout << "Kth distinct string: " << result << endl;

    return 0;
}
