/*

Problem : https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

Solution :

Serialize : level order traversal, convert data values to string

Deserialize : Use istringstream to get data and store them in a vector
of ints. Then make a treequeue and create nodes and store in this treequeue
and level order traversal

Time complexity : O(n)
Space complexity : O(n)
n -> size of binary tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        string result;
        if(root == nullptr) return result;

        // Create a queue to store TreeNode*
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty())
        {
            // Get current size
            int size = q.size();

            // Go over all TreeNode*
            for(int i = 0; i < size; i++)
            {
                // Get the front pointer and pop it out
                TreeNode* currentNode = q.front();
                q.pop();

                // If not nullptr
                if(currentNode)
                {
                    // Store its value in a string and
                    // Push its children into queue
                    result += to_string(currentNode->val);
                    q.push(currentNode->left);
                    q.push(currentNode->right);
                }

                // If nullptr
                else
                {
                    // Store null
                    result += "null";
                }

                // Delimiter to use istringstream
                // during deserialize to get words
                result += " ";
            }
        }

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        TreeNode *root = nullptr;
        if(data.length() == 0) return root;

        // Create queue to hold all ints
        queue<int> q;

        // Use istringstream
        istringstream iss(data);
        string word;

        // Pour the words from stringstream into word string
        while(iss >> word)
        {
            // Store the value
            if(word == "null") q.push(INT_MAX);
            else q.push(stoi(word));
        }

        // Create root using front of queue
        root  = new TreeNode(q.front());
        q.pop();

        // Make a queue of TreeNode*
        queue<TreeNode*> tq;

        // Push the root created above into treequeue
        tq.push(root);

        // While the tree queue is not empty
        while( !tq.empty() )
        {
            // Get the front of tree queue and pop it out
            TreeNode *current =  tq.front();
            tq.pop();

            // Get the front int of queue and pop it out
            int leftData = q.front();
            q.pop();

            // If data is valid, create node and store
            if(leftData != INT_MAX)
            {
              current->left = new TreeNode(leftData);
              tq.push(current->left);
            }

            // Get the front int of queue and pop it out
            int rightData = q.front();
            q.pop();

            // If data is valid, create node and store
            if(rightData != INT_MAX)
            {
              current->right = new TreeNode(rightData);
              tq.push(current->right);
            }
        }

        return root;
    }
};



// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));