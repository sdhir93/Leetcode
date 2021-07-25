/*

Problem : https://leetcode.com/problems/merge-sorted-array/

Solution :

- Start from last index adn store number based on comparison

- Corner case when nums1 has invalid entries only

Time complexity : O(m + n)
Space complexity : O(1)
m -> number of entries in nums1
n -> number of entries in nums2

*/

class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        // Initialize last indices of nums1, nums2
        // and resultant nums1
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0 && k >= 0)
        {
            if (nums1[i] > nums2[j]) nums1[k--] = nums1[i--];

            else if (nums1[i] < nums2[j]) nums1[k--] = nums2[j--];

            else
            {
                nums1[k--] = nums1[i--];
                nums1[k--] = nums2[j--];
            }
        }

        // Corner case when there was no valid entry in nums1
        while (j >= 0) nums1[j--] = nums2[j];
    }
};