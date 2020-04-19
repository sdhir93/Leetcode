/*
Problem: https://leetcode.com/problems/sliding-window-maximum/

Solution:

- Data structure required: deque
    - So that last and first element are accessible in O(1)

- Idea is to store indices of max elements in an array by

    - First pushing k elements into dq

    - Removing front if out of window

    - Removing elements from the back if smaller than current element

- At the end, store elements from the indices

Time complexity : O(n)
Space complexity : O(n)
n -> size of input vector
*/
class Solution
{

private:
    deque<int> dq;
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k)
    {
        // Vector to store max elements
        vector<int> result;

        // Vector to store indices of max elements
        vector<int> index;

        int i = 0;

        // Go voer the first k elements
        for(; i < k; i++)
        {
            // Keep removing elements from the back of dq
            // i.e. pop all small elements till dq is not empty
            while(!dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }

            // Push this index to the back of the dq
            dq.push_back(i);
        }

        // The front of dq now contains index of the max
        // element amongst first k elements

        // Go over the rest of the elements
        for(; i < nums.size(); i++)
        {
            // store the index of max element
            // in this window
            index.push_back(dq.front());

            // If the index of maximum element
            // is out of window, slide the window
            while(!dq.empty() && dq.front() <= i - k)
            {
                // pop(remove) from front of the dq
                dq.pop_front();
            }


            // Keep removing elements from the back of dq
            // i.e. pop all small elements till dq is not empty
            while(!dq.empty() && nums[i] >= nums[dq.back()])
            {
                dq.pop_back();
            }

            // Push this index to the back of the dq
            dq.push_back(i);

        }

        // Store the index of max element
        // from the last window
        index.push_back(dq.front());

        // Store the elements corresponding to
        // indices of max element in all windows
        for(auto i : index)
        {
            result.push_back(nums[i]);
        }

        return result;
    }
};