/*
Problem: https://leetcode.com/problems/insert-into-a-binary-search-tree/

Insert into a Binary Search Tree

Solution:
- Iteratively search left and right nodes depending on val to be inserted

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {

        auto treeIterator = root;
        auto newNode = new TreeNode(val);
        
        while(treeIterator != nullptr)
        {
            if(treeIterator->val <= val) {
                // insert at left node
                if(treeIterator->left == nullptr) {
                    treeIterator->left = newNode;
                    break;
                } else treeIterator = treeIterator->left;
                
            } else {
                // insert at right
                if(treeIterator->right = nullptr) {
                    treeIterator->right = newNode;
                    break;
                } else treeIterator= treeIterator->right;  
            }
        }
        
        return treeIterator ? root: newNode;
    }
};