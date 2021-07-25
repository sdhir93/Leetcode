/*

Problem : https://leetcode.com/problems/cousins-in-binary-tree/

Solution :

- Maintain a queue and do level order traversal
- Set parent1 and parent 2 variables and decide

Time complexity : O(n)
Space complexity : O(n)
n -> size of input Tree

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
	bool isCousins(TreeNode* root, int x, int y)
    {
        // If root is nulll, return
	    if(!root) return root;

        // Create a queue of TreeNode* and push root
	    queue<TreeNode*> q;
	    q.push(root);

        // Initialize parents
	    int parent1 = -1, parent2 = -1;

        // While q contains elements
        while(!q.empty())
        {
            // Get current size
            int size = q.size();

            // Go over all elements in the queue
            for(int i = 0; i < size; i++)
            {
                // Get the front element of queue and pop it off
                TreeNode* curr = q.front();
                q.pop();

                TreeNode* left = curr->left;
                TreeNode* right = curr->right;

                if(left)
                {
                    // Push left onto queue and check its val
                    // Accordingly set parent 1, 2
                    q.push(left);
                    if(left->val == x) parent1 = i;

                    if(left->val == y) parent2 = i;
                }

                if(right)
                {
                    // Push right onto queue and check its val
                    // Accordingly set parent 1, 2
                    q.push(right);
                    if(right->val == x) parent1 = i;

                    if(right->val == y) parent2 = i;
                }
            }

            // Decide on the basis of values of parent1 and parent2
            if(parent1 == -1 && parent2 == -1) continue;

            else if (parent1 != -1 && parent2 != -1)
            {
                if (parent1 == parent2) return false;
                return true;
            }

            else return false;
        }

        return false;
    }
};