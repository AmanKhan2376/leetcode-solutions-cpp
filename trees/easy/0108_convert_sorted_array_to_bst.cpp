/*
Leetcode Problem 108: Convert Sorted Array to Binary Search Tree
----------------------------------------------------------------
Given an integer array nums where the elements are sorted in ascending order, 
convert it to a height-balanced binary search tree (BST).

A height-balanced binary tree is a binary tree in which the depth of the two 
subtrees of every node never differs by more than 1.

Approach:
---------
- Use divide and conquer / recursion:
    - The middle element of the array becomes the root.
    - Recursively build the left subtree from elements before the mid.
    - Recursively build the right subtree from elements after the mid.
- This ensures a balanced BST because the array is sorted.

Time Complexity:  O(n)   (each element is processed once)
Space Complexity: O(log n)   (recursion stack for balanced BST)
*/

#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }
    
private:
    TreeNode* buildBST(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;  // base case

        int mid = left + (right - left) / 2;  // avoid overflow
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);
        
        return root;
    }
};

// Example usage
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    vector<int> nums = {-10, -3, 0, 5, 9};
    Solution sol;
    TreeNode* root = sol.sortedArrayToBST(nums);

    cout << "Inorder traversal of BST: ";
    printInorder(root);
    cout << endl;

    return 0;
}
