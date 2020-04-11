/*
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
        
        // Go over all elements and save the index with
        // element as key
        // If (target - element) is already in the map
        // return the index of that element and current index
        for(int i = 0; i < nums.size(); i++)
        {
            if(umap.find(target - nums[i]) != umap.end())
            {
                return {umap[target - nums[i]], i};
            }
            
            umap[nums[i]] = i;
        }
        return {-1};
    }
    
};
