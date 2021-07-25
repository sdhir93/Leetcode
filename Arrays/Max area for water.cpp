/*

Problem : https://leetcode.com/problems/container-with-most-water/solution/

Solution :

Area is minimum of the two heights multiplied by diifference in their indices

Iterate using two pointer

Time complexity : O(n)
Space complexity : O(1)
n -> size of input vector

*/
class Solution {
public:
    int maxArea(vector<int>& heights)
    {
        // Initialize maxArea to update everytime we
        // calculate area as we iterate through array
        int maxArea = 0;

        // Initialize indices
        int low = 0;
        int high = heights.size() - 1;

        // Break condition
        while(low <= high)
        {
            // Get the height of towers
            int left = heights[low];
            int right = heights[high];

            // Calculate and store area
            maxArea = max( maxArea, min(left, right) * (high - low) );

            // Advance the index having larger height
            if(left >= right) high--;
            else low++;
        }

        return maxArea;
    }
};