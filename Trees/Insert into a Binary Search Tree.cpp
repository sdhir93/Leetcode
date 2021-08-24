/*
https://leetcode.com/problems/insert-into-a-binary-search-tree/

Insert into a Binary Search Tree

Solution 1: Recursion
- If root == nullptr return a new node
- recurse on right and left nodes

SC: O(H)
TC: O(H)

Solution 2: Iteration
- while treeTracker(== root) is not null
- keep on searching for a right or left node which is null and insert
- BST criteria to be inspected at each iteration

SC: O(1)
TC: O(H)
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
/* Solution 1: Recursion
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) return new TreeNode(val);
        
        if( val > root->val) root->right = insertIntoBST(root->right, val);
        else root->left = insertIntoBST(root->left, val);
        return root;
        
    }
};
*/

/* Solution 2: Iteration*/
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        auto new_node = new TreeNode(val);
        
        auto treeTracker = root;
        
        while(treeTracker != nullptr) {
            if(val > treeTracker->val) {
                if(treeTracker->right != nullptr) {
                    treeTracker = treeTracker->right;
                }
                else {
                    treeTracker->right = new_node;
                    return root;
                }
            }
            else {
                if(treeTracker->left != nullptr) {
                    treeTracker = treeTracker->left;
                }
                else {
                    treeTracker->left = new_node;
                    return root;
                }
            }
        }
        
        return new_node;
    }
};
