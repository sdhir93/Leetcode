/*
Problem: https://leetcode.com/problems/sort-colors/

Solution:

- Maintain three indices
    - low, mid, high

- Swap the numbers in such a way that
    - low index receives 0
    - mid index 1 (swap not needed)
    - high index receives 2 (dont increment mid index)

Time complexity : O(n)
Space complexity : O(1)
n -> size of input vector
*/

class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        int low = 0;
        int high = nums.size() - 1;
        int mid = 0;

        while(mid <= high)
        {
            int current = nums[mid];

            switch(current)
            {
                case 0:
                    swap(nums[low++], nums[mid++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid], nums[high--]);
                    break;
            }
        }
    }
};