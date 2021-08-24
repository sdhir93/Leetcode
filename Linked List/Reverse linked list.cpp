/*

Problem : https://leetcode.com/problems/reverse-linked-list/

Solution :

- Store current's next
- Set current's next to prev
- Set current as prev
- Set next as current

Time complexity : O(n)
Space complexity : O(1)
n -> size of input linked list

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        // If no or only one node, return head
        if(!head || !head->next ) return head;

        // Initialize prev, curr, next
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        // While curr is valid
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};