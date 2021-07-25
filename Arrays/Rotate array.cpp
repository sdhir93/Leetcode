/*
Problem: https://leetcode.com/problems/rotate-array/

Solution:

- This is an in place solution

- Adjust k by taking modulus

- Maintain 5 values
    - 2 indices - idxCurrent, idxNext
    - 2 elements - numPlacer, numKeeper
    - 1 int - count

- Move idNext and save its value as numKeeper

- Place numPlacer in idNext

Time complexity : O(n)
Space complexity : O(1)
n -> size of input vector
*/

class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        int size = nums.size();
        if (size == 0 || size == 1) return;

        // Set k between 0 to size - 1;
        k = k % nums.size() ;

        // Initialize indices
        int idxCurrent, idxNext;

        // Initialize numbers
        int numKeeper, numPlacer;

        // Check for break condition
        int count = 0;

        // Keep incrementing the start index till count is reached
        for(int idxStart = 0; count < size; idxStart++)
        {
            // Set current id to start id
            idxCurrent = idxStart;

            // Store the value at current id
            numPlacer = nums[idxCurrent];

            do
            {
                // Calculate next id according to current id, k and size
                idxNext = (idxCurrent + k) % size;

                // Store the value at next id
                numKeeper = nums[idxNext];

                // Place the value at next id saved earlier
                nums[idxNext] = numPlacer;

                // Save the value at next id for next iteration
                numPlacer = numKeeper;
                idxCurrent = idxNext;

                // Increment count for break condition
                count++;

            } while(idxCurrent != idxStart);
        }
    }

};