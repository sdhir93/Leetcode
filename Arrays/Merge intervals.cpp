/*
Problem: https://leetcode.com/problems/merge-intervals/

Solution:

- Sort the intervals in increasing order of start times

- Initialize ints start and end with the values from
the first interval

- Go over all intervals (from second to last)

    -check value of int end with the value of start (from the current interval)

    - If overlapping, set end as max of end and end from current interval

    - If not overlapping, then push back the result in a vector and
    set ints start and end as values from current interval

Time complexity : O(n)
Space complexity : O(n) -> depends on how many can we merge
n -> number of intervals in input vector
*/

class Solution
{

public:

    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        // Return if size is <= 1
        if(intervals.size()<=1)
        {
            return intervals;
        }

        // Sort the intervals depending on start values
        // Here comparator is anonymous function called lambda
        sort(intervals.begin(),intervals.end(),
            [](const vector<int>& a , const vector<int>& b)
             {
                 return a[0] < b[0];
             }
        );

        // Declare result vector
        vector<vector<int>> result;

        // Set st and en as start and end times of
        // the first interval
        int st = intervals[0][0];
        int en = intervals[0][1];

        // Go over all the intervals
        for(int i = 1; i < intervals.size(); i++)
        {
            // Check the en value against start interval
            if(intervals[i][0] <= en)
            {
                // Set en as max of en and end value
                // this interval
                en = max(en, intervals[i][1]);
            }
            else
            {
                // Store the result
                result.push_back({st,en});

                // Set the st and en values as
                // start and end of this interval
                st = intervals[i][0];
                en = intervals[i][1];
            }
        }

        // Store the last result
        result.push_back({st,en});

        return result;
    }
};
