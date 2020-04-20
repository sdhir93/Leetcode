/*
Problem: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

Solution:

Idea is to modify binary search to get the index having lowest number

Time complexity : O(logn)
Space complexity : O(1)
n -> size of input vector
*/

class Solution
{
public:
    int findMin(vector<int>& nums)
    {
        if(nums.empty()) return INT_MIN;

        // Initialize indices
        int low = 0;
        int high = nums.size() - 1;

        // Break condition
        while(low < high)
        {
            int mid = (high - low)/2 + low;

            // If midnumber greater than last number,
            // lowest index must be somewhere in upper half
            if( nums[mid] > nums[high]) low = mid + 1;

            // If array seems sorted, reduce high to mid
            else high = mid;
        }

        return nums[low];
    }
};