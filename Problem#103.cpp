/*

Problem : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

Solution :

- Do a level order traversal
- Change the index of the vector according to the
direction of leftToRight

Time complexity : O(n)
Space complexity : O(n)
n -> size of input tree

*/
/* Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        // Return empty result if root is nullptr
        vector<vector<int>> result;
        if(!root) return result;

        // Create a queue to do level order
        // traversal and push the root
        queue<TreeNode*> q;
        q.push(root);

        // Flag to manage the index
        bool leftToRight = true;

        // While the q is not empty
        while(!q.empty())
        {
            // Get the current size of q
            int size = q.size();

            // Initialize a vector v
            vector<int> v(size);

            // Go over all the elements
            for(int i = 0; i < size; i++)
            {
                // Get the front node and pop it off
                TreeNode* curr = q.front();
                q.pop();

                // Calculate index
                int index = 0;
                if(leftToRight) index = i;
                else index = size - 1 -i;

                // Store the current value in the vector
                v[index] = curr->val;

                // Push the left and right into queue
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            // Change the direction
            leftToRight = !leftToRight;

            // Store the result
            result.push_back(v);
        }

        return result;
    }
};