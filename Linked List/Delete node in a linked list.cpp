/*

Problem : https://leetcode.com/problems/delete-node-in-a-linked-list/

Solution :

- Copy the value of next node and delete it

Time complexity : O(1)
Space complexity : O(1)

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
    void deleteNode(ListNode* node)
    {
        // Store value of next node here
        node->val = node->next->val;

        // Save the node to be deleted
        ListNode* toDelete = node->next;

        // Link the next pointer
        node->next = node->next->next;

        delete toDelete;
    }
};