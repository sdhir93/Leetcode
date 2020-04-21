/*
Problem: https://leetcode.com/problems/diameter-of-binary-tree/

Solution:

- Perform depth first search to find maximum depth of
left subtree and right subtree

Time complexity : O(n)
Space complexity : O(1)
n -> size of binary tree
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        // Pass the result as referene
        int result = 0;

        // Perform depth first search
        dfs( root, result );

        return result;
    }

    // This function is called recursively
    // Notice return value is not used above
    // Only concerned with computing result
    int dfs( TreeNode* node, int &result)
    {
        if(!node) return 0;

        int left = dfs(node->left, result);
        int right = dfs(node->right, result);

        // Store max result in result variable
        result = max(result, left + right);

        // Return maximum among left and right and add 1
        return 1 + max(left, right);
    }
};