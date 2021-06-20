/*

Problem : https://leetcode.com/problems/copy-list-with-random-pointer/

Solution :

- Go through each old node
    - create new node and set its next pointer
      to next old node
    - Set old node's next to new node
    - Advance old head iterator to next node in old list

- Copy random pointers
    - Go through each old node
    - Set random pointer of next node(which is now new node)
      to old node's random's next node
    - Advance old head iterator

- Split/ Unweave both lists
    - Go thorugh each old node
    - Revert all next old nodes to original
      by getting original next from new node's next
    -

Time complexity : O(n + n + n)
Space complexity : O(1) or O(n)
n -> length of linked list

*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {

        // Error checking
        Node* old_head_iter = head;
        if(!old_head_iter) return NULL;

        // Go through each old node
        while(old_head_iter)
        {
            // Create a new node
            Node * new_node = new Node(old_head_iter->val);

            // set its next pointer to next old node
            new_node->next = old_head_iter->next;

            // Set old node's next to new node
            old_head_iter->next = new_node;

            // Advance old head iterator
            old_head_iter = new_node->next;
        }

        // Revert old head iterator to original head position
        old_head_iter = head;

        // Go through each old node
        while(old_head_iter)
        {
            // Set the random pointer of new nodes
            old_head_iter->next->random = (old_head_iter->random) ? old_head_iter->random->next : NULL;

            // Advance old head iterator
            old_head_iter = old_head_iter->next->next;
        }

        old_head_iter = head;
        Node* result = old_head_iter->next;
        Node* new_head_iter = result;

        // The two lists are now weaved. Unweave them
        while(old_head_iter)
        {
            // Revert back all the next nodes to original
            old_head_iter->next = new_head_iter->next;

            // Advance the old head iterator
            old_head_iter = new_head_iter->next;

            // Set next pointers for new list
            if(old_head_iter)
            {
                // Set new head iter next to old head iter next
                new_head_iter->next = old_head_iter->next;

                // Advance new head iter
                new_head_iter = new_head_iter->next;
            }
        }

        return result;
    }

};