/*
Problem: https://leetcode.com/problems/top-k-frequent-elements/

Solution:

Solution Source : https://leetcode.com/problems/top-k-frequent-elements/discuss/444014/Simple-C%2B%2B-bucket-sort-w-analysis

- Require two data structures
    - Frequency map (unordered map)
    - Bucket (vector<vector<int>>)

- Each element can appear at most n times in the array,
so the bucket will have a size of n + 1
(appear 0 time, 1 time, 2 times ... n times)

- Starting from the most frequent element (at the end
of the bucket), we keep pushing all the element within
that bucket to our return list until the return list
is of size k.

Time complexity : O(n + m + (n - k) * n / m) = O(n)

Space complexity : O(n) + 2*O(k) = O(n)

- n is total element in nums, m is total number of distinct
element (m <= n),
thus average frequency of each word is n / m

*/

class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        // Get size of input vector
        const int n = nums.size();

        // Frequency map that maps int to its frequency
        unordered_map<int, int> freqMap;

        for (int n : nums) freqMap[n]++;

        // Bucket of size n + 1 that can contain
        // actual elements
        // Example if bucket 3 contains 4,5
        // it means elements 4, 5 appear 3 times
        vector<vector<int>> bucket(n + 1);

        // Go over the entries in the map
        for (auto p : freqMap)
        {
            // Get the frequency using second
            int freq = p.second;

            // Push the element into its bucket
            bucket[freq].push_back(p.first);
        }

        // Initialize the result
        vector<int> res;

        // Start from the end bucket
        for (int i = n; i >= 0; i--)
        {
            // Within this bucket, there
            // could be more than 1 elements
            for (int element : bucket[i])
            {
                // Store the elements in result
                res.push_back(element);

                // Return result when size k is reached
				if (res.size() == k) return res;
			}
        }

        return res;
    }
};