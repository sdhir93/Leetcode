/*

Problem : https://leetcode.com/problems/max-area-of-island/

Solution :

- Go over rows and columns and find a cell that has an island

- Expand this island in all directions, mark the cell as visited
by changing the value in cell to an invalid value and increment its
size

Time complexity : O(m * n)
Space complexity : O(1)

m -> No. of rows of input grid
n -> No. of cols of input grid
s
*/
class Solution
{
 private:

    int m; // No. of rows
    int n; // No. of columns

    void search(int x, int y, vector<vector<int>> &islands, int& area)
    {
        if (x >= 0 && x < m && y >= 0 && y < n &&
            islands[x][y] == 1)
        {
            // Mark as visited and increment island size
            islands[x][y] = 0;
            area++;

            // Search in North, South, East and West direction
            search(x+1, y, islands, area);
            search(x, y+1, islands, area);
            search(x, y-1, islands, area);
            search(x-1, y, islands, area);
        }
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid)
    {
        // Initialize the maxArea, rows and cols
        int maxArea = 0;
        m = grid.size();
        if( m == 0 ) return maxArea;

        n = grid[0].size();
        if( n == 0 ) return maxArea;

        // Go over all rows and cols
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // check if this cell is part of island i.e. 1
                if (grid[i][j] == 1)
                {
                    int area = 0;

                    // call the search funciton to calculate area
                    search(i, j, grid, area);

                    // Store maxArea
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};