/*
Problem: https://leetcode.com/problems/search-in-rotated-sorted-array/

Solution:

Idea is to modify binary search to check which half the target lies

Time complexity : O(logn)
Space complexity : O(1)
n -> size of input vector
*/

class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        if(nums.size() == 0) return -1;

        // Initialize indices
        int low = 0;
        int high = nums.size() - 1;
        int mid = 0;

        // Initialize numbers
        int midNum = 0;
        int firstNum = nums[0];

        // Break condition
        while (low <= high)
        {
            // Get the current mid number
            mid = (low + high)/2;
            midNum = nums[mid];

            cout << midNum << endl;

            // If target met, return index
            if (midNum == target) return mid;

            if ( (midNum >= firstNum && firstNum > target) ||
                 (midNum < target && (midNum >= firstNum || firstNum > target )) )
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return -1;
    }
};