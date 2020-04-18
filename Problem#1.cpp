/*
Problem: https://leetcode.com/problems/two-sum/

Solution: Make an unordered map with key as element and value as index
of that element and check whether we find (target  - element) in the map

Time complexity : O(n)
Space complexity : O(n)
n -> size of input vector
*/

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        // Create an unordered map of two ints
        // first int will store the array element
        // second element stores index
        unordered_map<int, int> umap;

        // If (target - element) is already in the map
        // return the index of that element and current index
        for(int i = 0; i < nums.size(); i++)
        {
            if(umap.find(target - nums[i]) != umap.end())
            {
                return {umap[target - nums[i]], i};
            }

            // save the index as value with element as key
            umap[nums[i]] = i;
        }

        return {-1};
    }
};
