/*

Problem : https://leetcode.com/problems/range-sum-of-bst/

Solution :

- Store data in a sum variable if it matches the criteria

- Do recursive calls on left and right subtree

Time complexity : O(n)
Space complexity : O(1)
n -> number of elements in the tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int sum = 0;
public:
    int rangeSumBST(TreeNode* root, int L, int R)
    {
        // Return 0 if nullptr
        if(!root) return 0;

        // Get the data
        int data = root->val;

        // Compare and store data
        if( data >= L && data <= R ) sum += data;

        // Recursive call on left
        rangeSumBST(root->left, L, R);

        // Recursive call on right
        rangeSumBST(root->right, L, R);

        return sum;
    }
};