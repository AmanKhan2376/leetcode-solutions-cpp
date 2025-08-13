/*
LeetCode Problem 1108: Defanging an IP Address
----------------------------------------------
Given a valid IPv4 address `address`, return a defanged version of that IP address.  
A defanged IP address replaces every period `.` with `[.]`.

Approach:
---------
- Initialize an empty string `ans`.
- Iterate through each character `ch` in the input `address`.
- If `ch` is '.', append "[.]" to `ans`.
- Otherwise, append `ch`.
- Return the resulting string.

Time Complexity:  O(n), where n is the length of the input string.
Space Complexity: O(n), for the new string created.

*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string ans = "";
        for (char ch : address) {
            if (ch == '.') ans += "[.]";
            else ans += ch;
        }
        return ans;
    }
};

// Example usage
int main() {
    string address = "192.168.0.1";
    Solution sol;
    cout << "Defanged IP: " << sol.defangIPaddr(address) << endl;
    return 0;
}
