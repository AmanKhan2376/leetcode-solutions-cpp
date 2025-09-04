/*
Leetcode Problem 3516: Find Who Reaches Person 3 First
------------------------------------------------------
You are given three integers x, y, and z, representing the positions of 
three people on a number line:

- x is the position of Person 1.
- y is the position of Person 2.
- z is the position of Person 3 (stationary).

Both Person 1 and Person 2 move toward Person 3 at the same speed.

Return:
- 1 if Person 1 arrives first.
- 2 if Person 2 arrives first.
- 0 if both arrive at the same time.

Approach:
---------
- Compute |z - x| → distance of Person 1 from Person 3.
- Compute |z - y| → distance of Person 2 from Person 3.
- Compare distances:
    - If Person 1 is closer → return 1.
    - If Person 2 is closer → return 2.
    - If equal → return 0.

Time Complexity:  O(1)
Space Complexity: O(1)
*/

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int findClosest(int x, int y, int z) {
        int d1 = abs(z - x);
        int d2 = abs(z - y);
        if (d1 < d2) return 1;
        else if (d2 < d1) return 2;
        return 0;
    }
};

// Example usage
int main() {
    Solution sol;
    cout << sol.findClosest(2, 6, 4) << endl;  // Output: 1 (Person 1 closer)
    cout << sol.findClosest(10, 3, 7) << endl; // Output: 2 (Person 2 closer)
    cout << sol.findClosest(5, 9, 7) << endl;  // Output: 0 (same distance)
    return 0;
}
