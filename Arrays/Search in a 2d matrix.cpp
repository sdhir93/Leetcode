/*

Problem: https://leetcode.com/problems/search-a-2d-matrix/submissions/

Solution:

- The problem falls into the modified binary search problems

- The solution is using two binary searches, first to identify the row
and second to identify the column

Time complexity : O(log(m) + log(n))
Space complexity : O(1)
n -> no. of rows in input matrix
m -> no. of columns in input matrix
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        // Get the number of rows
        int rows = matrix.size();
        if(rows == 0) return 0;

        // Get the number of columns
        int cols = matrix[0].size();
        if(cols == 0) return 0;

        // Binary Search to find the row
        int low = 0;
        int high = rows - 1;
        int mid = 0;

        while(high >= low)
        {
            // Get the middle index
            mid = (high + low)/2;

            // Get the first and last elements in the middle row
            int firstElement = matrix[mid][0];
            int lastElement = matrix[mid][cols - 1];

            // If target found then return true
            if ( firstElement == target || lastElement == target ) return true;

            // If target is within this row, break
            else if ( firstElement < target && lastElement > target ) break;

            // If target is larger than the last element, search in upper half
            else if ( lastElement < target ) low = mid + 1;

            // If target is smaller than the first element, search in lower half
            else if( firstElement > target ) high = mid - 1;
        }

        // Re initialize the indices
        low = 0;
        high = cols - 1;

        // Perform binary search to find element
        while(high >= low)
        {
            // Get the newmid id and element within the mid row
            int newMid = (high + low)/2;
            int element = matrix[mid][newMid];

            // If target found, return true
            if(element == target) return true;

            // If target is smaller, search in lower half
            else if(element > target) high = newMid - 1;

            // If target is larger, search in upper half
            else if(element < target) low = newMid + 1;
        }

        return false;
    }
};