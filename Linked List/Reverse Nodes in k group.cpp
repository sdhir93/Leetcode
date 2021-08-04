/*
https://leetcode.com/problems/reverse-nodes-in-k-group/

Reverse Nodes in K group

- Use recursion on reverse nodes in a linked list
- If length is less than k do not reverse

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
private:
        int len(ListNode* ptr) {
            
            int length = 0;
            
            while(ptr != nullptr) {
            
                ptr = ptr -> next,
                length++;
            }
            
            return length;
        }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
      
        if(head == nullptr) return head;
        
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        ListNode* curr = head;
        int size = k;
        
        if(len(curr) < k) return head;

        while(curr != nullptr and size)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            size--;
        }
        
        if(next != nullptr) head->next = reverseKGroup(next, k);
        
        return prev;
        
    }
};