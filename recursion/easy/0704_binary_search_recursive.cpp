/*
Leetcode Problem 704: Binary Search
------------------------------------
Given a sorted array of integers and a target value, 
return the index of the target if it exists, otherwise return -1.

Approach (Recursive Binary Search):
------------------------------------
- Use divide and conquer:
  * Calculate mid = (s + e) / 2
  * If nums[mid] == target → return mid
  * If nums[mid] > target → search in left half
  * Else → search in right half
- Base case: if s > e, return -1.

Time Complexity:  O(log n)
Space Complexity: O(log n)   (due to recursion stack)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int bs(vector<int>& nums, int t, int s, int e) {
        if (s > e) return -1;

        int mid = s + (e - s) / 2;
        
        if (nums[mid] == t) {
            return mid;
        } else if (nums[mid] > t) {
            return bs(nums, t, s, mid - 1);
        } else {
            return bs(nums, t, mid + 1, e);
        }
    }

    int search(vector<int>& nums, int target) {
        return bs(nums, target, 0, nums.size() - 1);
    }
};

// Example usage
int main() {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    int result = Solution().search(nums, target);

    cout << "Target " << target << " found at index: " << result << endl;

    return 0;
}
