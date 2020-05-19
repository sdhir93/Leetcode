/*

Problem : https://leetcode.com/problems/maximum-depth-of-binary-tree/

Solution :

- Make recursive calls on left and right side of the tree

Time complexity : O(n)
Space complexity : O(n)
n -> no. of elements in tree

*/
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
public:
    int maxDepth(TreeNode* root)
    {
        // If root is nullptr, then retuen 0
        if(!root) return 0;

        // Calculate max of right and left
        return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    }
};