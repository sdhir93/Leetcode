/*
https://leetcode.com/problems/reverse-nodes-in-k-group/

Reverse linked list in K Group

Solution: 
- Have a reverse function
- Have start and stops
- Start with both start and stop nodes as heads
- Advance stop node by k - 1 times and set its next to nullptr
- Apply reverse function
- Advance the nodes

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
    ListNode* reverse(ListNode* head) {
        if(head == nullptr or head->next == nullptr) return head;
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = head->next;
        
        while(next) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head == nullptr or head->next == nullptr) return head;
        
        ListNode* dummy = new ListNode();
        
        ListNode* prev = dummy;
        ListNode* start = head;
        ListNode* stop = head;
        
        while(start) {
           
            int temp = k - 1;
            
            while (stop && temp) {
                temp--;
                stop = stop->next;
            }
            
            // Checks the last node group less than k
            if(stop == nullptr) return dummy->next;
            
            // Store next before reversing
            ListNode* next = stop->next;
            stop->next = nullptr;
            
            // Reverse and attach
            prev->next = reverse(start);
            start->next = next;
            
            // Set prev as current start
            prev = start;
            
            // Advance start and set stop as start
            // for next iteration
            start = start->next;
            stop = start;
        }
        
        return dummy->next;
    }

   
};