/*

Problem : https://leetcode.com/problems/boundary-of-binary-tree/

Solution :

PreOrder and PostOrder Traversal

Time complexity : O(n)
Space complexity : O(n)
n -> size of input tree

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
private:
    vector<int> boundary;

public:
    vector<int> boundaryOfBinaryTree(TreeNode* root)
    {
        // If root is nullptr, return empty result
        if(!root) return boundary;

        boundary.push_back(root->val);

        if(!root->left && !root->right) return boundary;

        // Add left boundary to result
        if(root->left) leftBoundary(root->left);

        // Add leaves to result
        addLeaves(root);

        // Add right boundary to result
        if(root->right) rightBoundary(root->right);

        return boundary;

    }


    void leftBoundary(TreeNode* root)
    {
        if(!root->left && !root->right) return;

        boundary.push_back(root->val);

        if(root->left)
        {
            leftBoundary(root->left);
            return;
        }

        leftBoundary(root->right);
        return;
    }

    void rightBoundary(TreeNode* root)
    {
        if(!root->left && !root->right) return;

        if(root->right)
        {
            rightBoundary(root->right);
            boundary.push_back(root->val);
            return;
        }

        rightBoundary(root->left);

        boundary.push_back(root->val);
        return;
    }

    void addLeaves(TreeNode* root)
    {
        if(!root) return;
        if(!root->left && !root->right) boundary.push_back(root->val);

        addLeaves(root->left);
        addLeaves(root->right);
        return;
    }
};