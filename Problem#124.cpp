/*

Problem : https://leetcode.com/problems/binary-tree-maximum-path-sum/

Solution :

Idea is to implement a recursive solution using dfs

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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
private:
    int maxSum = INT_MIN;

public:
    int dfs(TreeNode* root)
    {
        if(!root) return 0;

        int data = root->val;

        // These two lines are making recursive calls
        // and computing max gain from their respective nodes
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));

        // Store the max sum
        maxSum = max(maxSum, left + right + data);

        // Used in line 41 and 42 to return an int
        return max(left, right) + data;
    }

    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;

        // Perform dfs
        dfs(root);

        return maxSum;
    }
};