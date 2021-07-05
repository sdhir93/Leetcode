/*
Problem: https://leetcode.com/problems/dlete-operation-for-two-strings/

Solution:

- Calculate longest common subsequence
    - Init dp array of (m + 1) * (n + 1)
    - Go over 2d array
    - If prev elements equal, then dp = 1 + prev dp
    - If prev elements not equal, then dp = max (prev dp diagonal)

- Subtract LCS from both strings and add them both to get deletion distance

Time complexity: O(m * n)
Space complexity: O(m * n)

*/

class Solution {
public:
    int LCS(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();
        
        int dp[m + 1][n + 1];
        
        memset(dp, 0, sizeof(dp));
        
        for(int i = 1; i <= m ; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[m][n];
    }
    
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        int lcs = LCS(word1, word2);
        
        return (m + n - (2 * lcs));
 
    }
};
