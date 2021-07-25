/*
Problem: https://leetcode.com/problems/maximum-subarray/

Solution:

- Kadane's algorithm
    - For each element
    - Accumulate
    - Store the answer using max
    - Reset the accumulator

Time complexity : O(n)
Space complexity : O(1)

*/
class Solution {
public:

    int maxSubArray(vector<int>& nums)
    { 
        int accumulator = 0;
        int answer = INT_MIN;
        for(auto num : nums)
        {
            // Add the element encountered in this iteration
            accumulator += num;

            // Store the new answer based on whether we
            // added a positive number or a negative number just now
            answer = max(answer, accumulator);

            // Reset accumulator for next iteration
            // This will drop the previous negative integers
            accumulator = max(0, accumulator);    
        }

        return answer;
    }
    
    
};