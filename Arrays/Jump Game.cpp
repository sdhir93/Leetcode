/*
Problem: https://leetcode.com/problems/jump-game/

Jump Game

Solution:
- Start from last index and mark it has lastGoodIndex
- Traverse backwards and test the condition i + nums[i] >= lastGoodIndex
    - If true , set the lastGoodIndex as i
- In the end, test whether lastGoodIndex == 0;

TC: O(n)
SC: O(1)

*/

class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        // Init lastGoodIndex as last element
        int lastGoodIndex = nums.size() - 1;
        
        // Traverse backwards
        for(int i = nums.size() - 1; i >= 0; i--) {
            
            // if we can reach lastgoodindex then reset it to i
            if(i + nums[i] >= lastGoodIndex) {
                lastGoodIndex = i;
            }
        }
        
        // Test if we reach the starting point
        return lastGoodIndex == 0;
    }
    
};
