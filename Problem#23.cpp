/*
Problem: https://leetcode.com/problems/merge-k-sorted-lists/submissions/

Solution:

- Push the first elements of the k lists into a minheap

- Make a fake node and attach the top element of minheap and remove it

- Push the next node of the top element above into minheap and keep on
repeating till minheap is empty

Time complexity : O(nlogk) -> each push into minheap takes logk
Space complexity : O(1);
n -> size of largest list
k -> total number of lists
*/


/**
 * Definition for singly-linked list.
 * struct ListNode
 * {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        // Create a type definition for Pair of int and ListNode*
        // Helpful to access as first and second
        typedef pair<int, ListNode*> Pair;

        // Priority queue: first argument is type of element,
        // second argument is always vector containing elements
        // of type in first argument, third argument is for sorting
        // Sorting is by first element of pair by defualt
        // We can change by writing a custom comparator
        priority_queue<Pair, vector<Pair>, greater<>> minHeap;

        // Go over all the lists
        for (int i = 0; i < lists.size(); ++i)
        {
            if (lists[i] != nullptr)
            {
                // Get pointer to all list
                ListNode *list = lists[i];

                // Pushes first element of all lists
                // into the minheap
                minHeap.push({list->val, list});
            }
        }

        // Create a fake node
        ListNode* list = new ListNode(-1);
        ListNode* curr = list;

        // Break condition: minheap is empty
        while (!minHeap.empty())
        {
            // Get the smallest element from top
            Pair p = minHeap.top();

            // Remove from the minheap
            minHeap.pop();

            // Set the next pointer and advance curr
            curr->next = p.second;
            curr = curr->next;

            // Get the next element from the list
            ListNode *next = p.second->next;

            // Push the next element into minheap
            if (next != nullptr) minHeap.push({next->val, next});
        }

        return list->next;
    }
};