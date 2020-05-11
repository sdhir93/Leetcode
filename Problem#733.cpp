/*

Problem : https://leetcode.com/problems/flood-fill/

Solution :

- Make recursive calls to left, right , up, down pixels
- Mark the pixel with new Color

Time complexity : O(m*n)
Space complexity : O(1)
m -> no. of rows
n -> no. of cols

*/
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        // If pixel already has same color, return image
        if (image[sr][sc] == newColor) return image;

        // Get size of rows and cols
        int rows = image.size();
        int cols = image[0].size();

        // Save the old color
        int oldColor = image[sr][sc];

        // Set new color
        image[sr][sc] = newColor;

        // top
        if (sr > 0 && image[sr - 1][sc] == oldColor)
          image= floodFill(image, sr - 1, sc, newColor);
        // bottom
        if (sr < rows - 1 && image[sr + 1][sc] == oldColor)
          image= floodFill(image, sr + 1, sc, newColor);
        // left
        if (sc > 0 && image[sr][sc - 1] == oldColor)
          image= floodFill(image, sr, sc - 1, newColor);
        //right
        if (sc < cols - 1 && image[sr][sc + 1] == oldColor)
          image= floodFill(image, sr, sc + 1, newColor);

        return image;
    }
};