/*
https://leetcode.com/problems/longest-common-subsequence/

Solution:

- Go over the dp array
    - If last chars equal then 1 + dp[i - 1][j - 1]
    - If not then max (dp[i - 1][j], dp[i][j - 1])

- Return dp[m][n]

- To save space i % 2 trick can be used since only 2 rows are used in one iteration 

Time complexity : O(n * m)
Space complexity : O(m)
m -> length of smaller string

*/
class Solution {
public:
    int longestCommonSubsequence(string s, string p) {
        
        // Init the string sizes
        int n = s.size();
        int m = p.size();
        
        // Init dp array
        int dp[2][m + 1];
        
        // Go over i and j
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                // Set the 0th row and column as zero
                if (i == 0 || j == 0)
                {
                    dp[i%2][j] = 0;
                }
                
                // If last chars equal then add 1 to prev dp
                else if (s[i - 1] == p[j - 1])
                {
                    dp[i%2][j] = 1 + dp[(i - 1)%2][j - 1];
                }
                
                // If unequal then store max (dp[i - 1][j], dp[i][j - 1])
                else
                {
                    dp[i%2][j] = max(dp[i%2][j - 1], dp[(i - 1)%2][j]);
                }
            }
        }
        
        // Return answer
        return dp[n%2][m];
    }
};