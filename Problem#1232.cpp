/*

Problem : https://leetcode.com/problems/check-if-it-is-a-straight-line/

Solution :

- Calculate slope using first two coordinates

- Verify that each coordinate has same slope

Time complexity : O(n)
Space complexity : O(1)
n -> size of input vector

*/
class Solution
{
public:
    bool checkStraightLine(vector<vector<int>>& coordinates)
    {
        // Get the size and retuen true if 2
        // Line passes through 2 points
        int size = coordinates.size();
        if(size == 2) return true;

        // Get slope using first two coordinates
        int x0 = coordinates[0][0];
        int y0 = coordinates[0][1];
        int dx = coordinates[1][0] - x0;
        int dy = coordinates[1][1] - y0;

        // Go over all other coordinates
        for(int i = 2; i < size; i++)
        {
            // Get current coordinates
            int xi = coordinates[i][0];
            int yi = coordinates[i][1];

            // If slope is not same, return false
            if( dy*(xi - x0) != dx*(yi - y0) ) return false;
        }

        return true;
    }
};