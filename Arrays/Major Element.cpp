/*
https://leetcode.com/problems/majority-element/

Majority Element

- Major Element will be n/2 times
- Increment count when major element
- decrement count when something else
- when count becomes 0, current element is major element

SC: O(1)
TC: O(n)
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int majorElem = 0;
        for(int num : nums) {
            if(count == 0) majorElem = num;
            
            count += (num == majorElem) ? 1 : -1;
        }
        
        return majorElem;
    }
};