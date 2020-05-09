/*

Problem : https://leetcode.com/problems/number-of-islands/

Solution :

- Go over rows and columns and find a cell that has an island

- Expand this island in all directions and mark the cell as visited
by changing the value in cell to an invalid value

Time complexity : O(m * n)
Space complexity : O(1)

m -> No. of rows of input grid
n -> No. of cols of input grid
*/
class Solution
{
private:

    int m; // No. of rows
    int n; // No. of columns

    void search(int x, int y, vector<vector<char>> &islands)
    {
        if (x >= 0 && x < m && y >= 0 && y < n &&
            islands[x][y] == '1')
        {
            // Mark as visited
            islands[x][y] = '$';

            // Search in North, South, East and West direction
            search(x+1, y, islands);
            search(x, y+1, islands);
            search(x, y-1, islands);
            search(x-1, y, islands);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid)
    {
        // Initialize the counr, rows and cols
        int count = 0;

        m = grid.size();
        if( m == 0 ) return count;

        n = grid[0].size();
        if( n == 0 ) return count;

        // Go over all rows and cols
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // check if this cell is part of island i.e. 1
                if (grid[i][j] == '1')
                {
                    // call the search funciton to find mark the island as visited
                    search(i, j, grid);

                    // Increment count
                    count++;
                }
            }
        }

        return count;
    }
};