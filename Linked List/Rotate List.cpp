/*
Problem: https://leetcode.com/problems/rotate-list/

Solution:

- Calculate position of new head by calculating size of
linked list

- LInk the head and tail

- Traverse till position and unlink new head and tail

Time complexity : O(n)
Space complexity : O(1)
n -> size of linked list
*/

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
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
    ListNode* rotateRight(ListNode* head, int k)
    {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* curr = head;

        int size = 1;

        while(curr->next)
        {
            curr = curr->next;
            size++;
        }

        // Join the head to the last element
        curr->next = head;

        // Calculate position of new head
        int position = size - (k % size);

        curr = head;

        while(position > 1)
        {
            curr = curr->next;
            position--;
        }

        head = curr->next;
        curr->next = nullptr;

        return head;
    }
};