/*
Leetcode Problem 1304: Find N Unique Integers Sum up to Zero
------------------------------------------------------------
Given an integer n, return any array containing n unique integers such that they add up to 0.

Approach:
---------
- Use pairs of positive and negative integers (i and -i).
- If n is even:
    - Fill the array with pairs until it reaches size n.
- If n is odd:
    - Do the same as even case, and add 0 at the end.
- This guarantees uniqueness and sum = 0.

Time Complexity:  O(n)   (one pass to fill the array)
Space Complexity: O(n)   (output array of size n)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        int idx = 0;
        for (int i = 1; i <= n / 2; i++) {
            ans[idx++] = i;
            ans[idx++] = -i;
        }
        if (n % 2 != 0) ans[idx] = 0;
        return ans;
    }
};

// Example usage
int main() {
    int n = 5;
    Solution sol;
    vector<int> result = sol.sumZero(n);

    cout << "Array with sum zero: ";
    for (int num : result) cout << num << " ";
    cout << endl;

    return 0;
}
