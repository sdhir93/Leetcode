/*

Problem : https://leetcode.com/problems/missiFindng-element-in-sorted-array/

Solution Source : https://leetcode.com/problems/missing-element-in-sorted-array/discuss/571270/C%2B%2B-binary-search-with-explanation

Solution :

- Calcualte number of missing elements

- If k is larger, then use a direct formula as below

- Otherwise, do a binary search
    - At every iteration calculate number of missing elements

- At the end, we are confident that low == high - 1,
so the k-th missing element (k is updated) is just nums[low] + k

Time complexity : O(n)
Space complexity : O(1)
n -> size of input vector
*/
class Solution
{
public:
    int missingElement(vector<int>& nums, int k)
    {
        // number of missing elements between the first and last element
        int missing = nums.back() - nums.front() - nums.size() + 1;

        if (k > missing)
        {
            // if k is larger than the missing counts, it means the k-th missing
            // element is larger than the last given number and can be easily calculated
            return nums.back() - missing + k;
        }

        // Initialize indices
        int low = 0;
        int high = nums.size() - 1;

        // Binary search
        while (low < high - 1)
        {
            // Get the middle index
            int mid = (high - low) / 2 + low;

            // calculate the number of missing elements between low and mid
            missing = nums[mid] - nums[low] - mid + low;

            if ( k > missing )
            {
                // the number of missing elements is smaller than k, so the element we want is not
                // between low and mid, we instead search between mid and high, but instead of
                // k-th, it will be (k-missing)-th
                k = k - missing;
                low = mid;
            }

            else
            {
                // the number of missing elements is larger than k, so the element we want is
                // between low and mid, replace high with mid and continue search
                high = mid;
            }
        }

        // at this point we are confident that low == high - 1, this means we have found
        // two consecutive numbers in the given array and all the elements between them
        // are missing, so the k-th missing element (k is updated) is just nums[lo]+k
        return nums[low] + k;
    }
};