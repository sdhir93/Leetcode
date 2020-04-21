/*
Problem: https://leetcode.com/problems/median-of-two-sorted-arrays/

Solution:

Idea is to perform binary search on the smaller array
and partition the other array accordingly i.e. move
startIndex and endIndex until this condition is met

 nums1Left <= nums2Right && nums1Right >= nums2Left

Time complexity : O(log(min(m,n))
Space complexity : O(1);
*/
class Solution
{
public:
    double getMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
		// It is guaranteed here that nums1.size() <= nums2.size()
        const int nums1Size = nums1.size();
        const int nums2Size = nums2.size();
        const int totalNums = nums1Size + nums2Size;

        // Initialize the indices
        int startIndex = 0;
        int endIndex   = nums1.size() - 1;

        // While median is not found
        while (1)
        {
            // Partition the smaller vector at middle index
            int nums1Partition = (endIndex - startIndex) / 2 + startIndex;

            // Partition the larger vector at the following index
            int nums2Partition = (totalNums / 2) - nums1Partition;

            int nums1Left = (nums1Partition <= 0) ? INT_MIN : nums1[nums1Partition - 1];
            int nums1Right = (nums1Partition >= nums1Size) ? INT_MAX : nums1[nums1Partition];

            int nums2Left = (nums2Partition <= 0) ? INT_MIN : nums2[nums2Partition - 1];
            int nums2Right = (nums2Partition >= nums2Size) ? INT_MAX : nums2[nums2Partition];


            // Check if the median is zeroed onto
            if (nums1Left <= nums2Right && nums1Right >= nums2Left)
            {
                // If total numbers are odd
                if (totalNums & 1) return (double)min(nums1Right, nums2Right);

                // If total numbers are even
                else
                {
                    int leftMedian = max(nums1Left, nums2Left);
                    int rightMedian = min(nums1Right, nums2Right);

                    return (double)(leftMedian + rightMedian) / 2;
                }
            }

            // Following adjustments are done to meet above
            // conditions and find median as above
            else if (nums1Left > nums2Right)
            {
                // move on left side of nums1
                endIndex = nums1Partition - 1;
            }

            else if (nums1Right < nums2Left )
            {
                // move on right side of nums1
                startIndex = nums1Partition + 1;
            }
        }

        return -1;
    }

    // Get median of larger array if smaller array is empty
    double getMedianSortedArray(vector<int>& nums)
    {
        // Get size of the input vector
        int numsSize = nums.size();

        // If size is odd
        if (numsSize & 1) return nums[numsSize / 2];

        // If size is even
        int leftMedianValue = nums[(numsSize / 2) - 1];
        int rightMedianValue = nums[numsSize / 2];

        // return the average
        return (double)(leftMedianValue + rightMedianValue) / 2;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        // Keep smallNums as alias for the array with smaller no. of elements
        vector<int>& smallNums = nums1.size() < nums2.size() ? nums1 : nums2;
        vector<int>& largeNums = (&smallNums == &nums1) ? nums2 : nums1;

        // If smaller array is empty, just calcualte median of that array
        if (smallNums.empty())
        {
            return getMedianSortedArray(largeNums);
        }

        return getMedianSortedArrays(smallNums, largeNums);
    }
};