/*
Problem: https://leetcode.com/problems/binary-tree-level-order-traversal/

Solution:

- Push the root into a queue of tree node poitners

- In a while loop, store the values pointed by the pointers
inside the queue and keep on adding the left and right pointers

Time complexity : O(n)
Space complexity : O(n)
n -> size of input vector
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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> result;

        if(!root) return result;

        queue<TreeNode*> q;

        // Push root into the queue
        q.push(root);

        // Break condition: empty queue
        while(!q.empty())
        {
            // Get the size of queue i.e. size of current level
            int size = q.size();

            // Vector to store values of current level
            vector<int> currentLevel;

            // Go over all elements in current level
            for(int i = 0; i < size; i++)
            {
                // Access the first element in queue
                TreeNode* curr = q.front();

                // Remove from the queue (front removed)
                q.pop();

                // Store the value in vector
                currentLevel.push_back(curr->val);

                // Push the TreeNode* into the queue
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            // Store this level's result in the result vector
            result.push_back(currentLevel);
        }

        return result;
    }
};