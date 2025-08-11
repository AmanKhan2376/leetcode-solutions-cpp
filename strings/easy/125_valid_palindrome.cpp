/*
Leetcode Problem: Valid Palindrome
----------------------------------
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Approach:
---------
- Use two pointers from start and end of the string.
- Skip any non-alphanumeric characters.
- Compare characters case-insensitively.
- If mismatch found, return false.
- Else, return true if pointers cross.

Time Complexity:  O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <string>
#include <cctype>  // for isalnum, tolower

using namespace std;

class Solution {
public:
    bool isPalindrome(string& s) {
        size_t start = 0, end = s.length() - 1;
        
        while (start <= end) {
            if (!isalnum(s[start])) {
                start++;
                continue;
            }
            if (!isalnum(s[end])) {
                end--;
                continue;
            }
            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            }
            start++;
            end--;
        }
        
        return true;
    }
};

int main() {
    Solution sol;

    string test1 = "A man, a plan, a canal: Panama";
    cout << boolalpha << sol.isPalindrome(test1) << endl;  // true

    string test2 = "race a car";
    cout << boolalpha << sol.isPalindrome(test2) << endl;  // false

    return 0;
}
