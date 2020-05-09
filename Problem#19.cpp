/*

Problem : https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Solution :

- Two pointers - slow and fast

- Move fast, increment a count and move slow only when this
count reaches n so that fast and slow are separated by n + 1 nodes

- If count is smaller then n, it means, return head->next

- Otherwise delete next of slow

Time complexity : O(n)
Space complexity : O(1)
n -> length of linked list

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if(!head) return nullptr;

        // Initialize fast and slow pointers
        ListNode* fast = head;
        ListNode* slow = head;

        // i represents difference between fast and slow pointers
        int i = 1;

        // Advance fast and slow so they have differene of n + 1 nodes
        while(fast && fast->next)
        {
            // Move slow pointer only when the fast pointer already
            // move n + 1 nodes in the list
            if(i > n) slow = slow->next;

            fast = fast->next;
            i++;
        }

        // Initialize a toDelete pointer
        // that holds node to be deleted
        ListNode* toDelete = nullptr;

        // List is small/equal to the given number
        if(n >= i)
        {
            toDelete = head;
            head = head->next;
        }

        // Slow pointer is pointing to prev node of the nth node
        // from end of the list
        else if(slow && slow->next)
        {
            toDelete = slow->next;
            slow->next = slow->next->next;
        }

        // Free the deleted node
        delete(toDelete);

        return head;
    }
};