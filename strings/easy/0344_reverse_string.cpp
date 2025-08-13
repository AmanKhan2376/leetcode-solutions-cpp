/*
LeetCode Problem 344: Reverse String
------------------------------------
Write a function that reverses a string. The input string is given as an array of characters `s`.
You must do this by modifying the input array in-place with O(1) extra memory.

Approach:
---------
- Use two pointers: one starting from the beginning (`left`), and one from the end (`right`).
- Swap the characters at `left` and `right`.
- Move `left` forward and `right` backward until they meet.
- This ensures the reversal is done in-place without extra space.
Or, use the built-in reverse() from <algorithm>, which runs in O(n) time and O(1) extra space.

Time Complexity:  O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

// Example usage
int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    Solution sol;
    sol.reverseString(s);
    cout << "Reversed String: ";
    for (char c : s) cout << c;
    cout << endl; // Output: "olleh"
    return 0;
}
