/*

Problem : https://leetcode.com/problems/interval-list-intersections/

Solution :

- Store the max of start time and min of end time if 2 conditions are met

1. A's start time is greter than equal to the B's start time
    and
2. A's start time is less than equal to B's end time

- Move the index that is finishing sooner i.e if A's end time is
smaller than B's end time, advance A

Time complexity : O(n)
Space complexity : O(1)
n -> size of input vector

*/
class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B)
    {
        vector<vector<int>> intersections;

        // Index for A and B
        int i = 0, j = 0;

        while( i < A.size() && j < B.size() )
        {
            // check if the interval A[i] intersects with A[j]
            // check if one of the interval's start time lies within the other interval
            if( ( A[i][0] >= B[j][0] && A[i][0] <= B[j][1] ) ||
                ( B[j][0] >= A[i][0] && B[j][0] <= A[i][1] ) )
            {
                // store the intersection part
                intersections.push_back( { max( A[i][0], B[j][0] ), min( A[i][1], B[j][1] ) } );
            }

            // move next from the interval which is finishing first
            if( A[i][1] < B[j][1] ) i++;
            else j++;
        }

        return intersections;
    }
};