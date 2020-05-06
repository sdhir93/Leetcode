/*

Problem : https://leetcode.com/problems/subarray-sum-equals-k/

Solution :

- Store the cumulative sum and increase its frequency every iteration

- If count of (sum - k) is >= 1, add frequency in the answer


Time complexity : O(n)
Space complexity : O(n)
n -> size of input vector

*/

class Solution
{
public:
    int subarraySum(vector<int>& nums, int k)
    {
        // First int is number, second int is frequency
        unordered_map<int ,int> umap;

        // Initialize sum and count
        int sum = 0;
        int count = 0;

        // Set 0 frequency as 1
        umap[0] = 1;

        // Go over all nums
        for ( int x : nums)
        {
            // Increment sum by x so it becomes cumulative sum
            sum += x;

            // Count how many times sum - k
            // appears in the map
            if ( umap.count(sum - k) ) count += umap[sum - k];

            // Increment frequency of cumulative sum
            umap[sum]++;
        }

        return count;
    }
};