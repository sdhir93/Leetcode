/*

Problem : https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/

Solution :

Check for three conditions

- InsertNode is middle
- InsertNode is at end
- InsertNode is last

Time complexity : O(n)
Space complexity : O(1)
n -> size of input circular linked list

*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution
{
public:
    Node* insert(Node* head, int insertVal)
    {
        // Create a new node
        Node* insertNode = new Node(insertVal);

        // If input is empty
        if(!head)
        {
            // Set next as insertNode and return
            insertNode->next = insertNode;
            return insertNode;
        }

        // Get the head in curr
        Node* curr = head;

        // Check for valid insertion point
        while(1)
        {
            // Three conditions need to be checked, either should be true
            // 1. 1->2->3...6->7 Insert 5
            // 2. 1->2->3        Insert 0 or 5
            // 3. 1              Insert anything
            if( (insertVal >= curr->val && insertVal <= curr->next->val) ||
                (curr->val > curr->next->val && (insertVal >= curr->val || insertVal <= curr->next->val)) ||
                curr->next == head )
            {
                // Set the next pointers
                insertNode->next = curr->next;
                curr->next = insertNode;
                break;
            }

            // Advance to next
            curr = curr->next;
        }

        return head;
    }
};