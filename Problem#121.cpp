/*
Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/

Solution:

Keep track of the maximum element from the right
because it is given that larger element is towards right

Time complexity : O(n)
Space complexity : O(1)
n -> size of input vector
*/
class Solution
{
public:
    int maxProfit(vector<int>& arr)
    {
        int maxDiff = 0;
        int n = arr.size();

        // Initialize max element from right side
        int maxRight = arr[n-1];

        // Go over all elements from right
        for (int i = n - 2; i >= 0; i--)
        {
            int num = arr[i];

            // larger element is towards right
            if (num > maxRight) maxRight = num;

            // Store maximum difference
            else maxDiff = max(maxDiff, maxRight - num);
        }

        return maxDiff;
    }
};