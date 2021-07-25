/*
Problem: https://leetcode.com/problems/fruit-into-baskets/

Solution:

The problem is find maximum count of two consecutive integers in an array

- Track lastFruit and SecondLastFruit
    - if current fruit is lastFruit
        - increment currentMax and lastCount

    - if current fruit is not lastFruit
        - check if current fruit is secondLastFruit
        - set current max according to above condition
        - set secondLastFruit = lastFruit
        - set lastFruit = current fruit
        - set lastCount as 1

- Save maximum of currentMax and maxCount

Time complexity : O(n)
Space complexity : O(1)
n -> size of input vector
*/
class Solution
{
public:
    int totalFruit(vector<int>& tree)
    {
        int maxCount  = 0;
        int currmax   = 0;
        int lastFruit = -1;
        int lastCount = 0;
        int secondLastFruit = -1;

        // Go over all the fruits in the tree vector
        for(int fruit : tree)
        {
            // If current fruit is lastFruit
            if(fruit == lastFruit )
            {
                // Increment current max and lastCount
                currmax++;
                lastCount++;
            }
            else
            {
                // Special condition if we encounter secondLastFruit again
                currmax = (fruit == secondLastFruit) ? currmax + 1 : lastCount + 1;

                // Set the fruits current status
                secondLastFruit = lastFruit;
                lastFruit = fruit;

                // Current fruit count = 1
                lastCount = 1;
            }

            // Store maximum of max count and current max
            maxCount = max(maxCount, currmax);
        }

        return maxCount;
    }
};