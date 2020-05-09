/*

Problem : https://leetcode.com/problems/binary-tree-right-side-view/

Solution :

- Do a level order traversal and store starting from
right child and then left

- Have a flag seen and set it true after pushing right most
child at every level

Time complexity : O(n)
Space complexity : O(log n) -> only store 1 node per level
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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root)
    {
        // Result vector
        vector<int> result;
        if (!root) return result;

        // Create a queue of TreeNode*
        queue<TreeNode*> q;
        q.push(root);

        // Flag to store right most element
        bool seen = false;

        // While q is not empty
        while (!q.empty())
        {
            // Set the flag as false
            seen = false;
            int size = q.size();

            // Go over current size
            for (int i = 0; i < size; i++)
            {
                // Get front of queue and pop it off
                TreeNode* curr = q.front();
                q.pop();

                // If flag not set, this is
                // right most node
                if (!seen)
                {
                    // Store right most for this level
                    result.push_back(curr->val);

                    // Do not store further for this level
                    seen = true;
                }

                // Store right first and then left
                if (curr->right) q.push(curr->right);
                if (curr->left) q.push(curr->left);
            }
        }

        return result;
    }
};
