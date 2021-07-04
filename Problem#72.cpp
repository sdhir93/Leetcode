/*
Problem: https://leetcode.com/problems/edit-distance/

Solution:

3 Solutions from bad to best

1st Solution - Brute force recursion
- Imagine that we are comparing last characters
- Cost of each replace, edit, transform is 1
- Base case is that we compare last character
- Call recursion if not equal

Time complexity: O(3^(mxn))
Space complexity: O(1)

----------------------------------------------------------------------------------

2nd Solution - DP with array dimensions (m + 1) x (n + 1) 
- Init a dp array of (m + 1) x (n + 1)
- Traverse through the 2d array
    - If string 1 is empty, number of edits = length of string 2
    - If string 2 is empty, number of edits = length of string 1
    - If both last characters are same, same as 1 less char on both strings
    - If both last characters are different, dp = 1 + min(Insert, Remove, Replace)  
- Return answer stored in dp[m][n]

Time complexity: O(mxn)
Space complexity: O(mxn)

----------------------------------------------------------------------------------

3rd Solution - DP with array dimensions (2) x (m + 1) 

NOTE: Dimensions are reversed here

- Init a dp array of (2) x (m + 1)
- Traverse through the 2d array
    - If string 1 is empty, number of edits = length of string 2
    - If string 2 is empty, number of edits = length of string 1
    - If both last characters are same, same as 1 less char on both strings
    - If both last characters are different, dp = 1 + min(Insert, Remove, Replace)  
- Return answer stored in dp[n%2][m]

Time complexity: O(mxn)
Space complexity: O(m)

*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        
        // Init the string lengths
        int m = word1.size();
        int n = word2.size();
        
        // Init the dp array 
        int dp[2][m + 1];
        
        // To fill the DP array with 0
        memset(dp, 0, sizeof(dp));
        
        // If string 2 is empty, number of edits = length of string 1
        for(int i = 0; i <= m; i++) dp[0][i] = i;
        
        // Traverse through the 2d array
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                
                // If string 2 is empty, number of edits = length of string 1
                if (j == 0) dp[i % 2][j] = i;
                
                // If both last characters are same, same as 1 less char on both strings
                else if(word1[j - 1] == word2[i - 1]) dp[i % 2][j] = dp[(i - 1) % 2][j - 1];
                
                // If both last characters are different, dp = 1 + min(Insert, Remove, Replace)
                else dp[i % 2][j] = 1 + mini(dp[i % 2]      [j - 1],  // Insert
                                             dp[(i - 1) % 2][j],      // Remove
                                             dp[(i - 1) % 2][j - 1]); // Replace
            }
        }
        
        // answer is stored in [n%2][m]
        return dp[n % 2][m];
    }
        
    // Utility function to find minimum of three numbers
    int mini(int x, int y, int z) { return std::min(std::min(x, y), z); }
    
};

// 2nd Solution - DP with array dimensions (m + 1) x (n + 1) 
/*
class Solution {
public:
    int minDistance(string word1, string word2) {
        
        // Init the string lengths
        int m = word1.size();
        int n = word2.size();
        
        // Init the dp array 
        int dp[m + 1][n + 1];
        
        // Traverse through the 2d array
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                
                // If string 1 is empty, number of edits = length of string 2
                if (i == 0) dp[i][j] = j;
                
                // If string 2 is empty, number of edits = length of string 1
                else if (j == 0) dp[i][j] = i;
                
                // If both last characters are same, same as 1 less char on both strings
                else if(word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                
                // If both last characters are diferent, dp = 1 + min(Insert, Remove, Replace)
                else dp[i][j] = 1 + mini(dp[i]    [j - 1],  // Insert
                                         dp[i - 1][j],      // Remove
                                         dp[i - 1][j - 1]); // Replace
            }
        }
        
        // answer is stored in dp[m][n]; 
        return dp[m][n];
    }
        
    // Utility function to find minimum of three numbers
    int mini(int x, int y, int z) { return std::min(std::min(x, y), z); }
    
};

----------------------------------------------------------------------------------

// 1st Solution - Brute force recursion
class Solution {
public:
    // Recursive
    int minDistance(string word1, string word2) {
        
        // Init the string lengths
        int m = word1.size();
        int n = word2.size();
        
        // If string 1 is empty, number of edits = length of string 2
        if(m == 0) return n;
        
        // If string 2 is empty, number of edits = length of string 1
        if(n == 0) return m;
  
        // If both last characters are same
        if(word1[m - 1] == word2[n - 1]) return (minDistance(word1.substr(0, m - 1), word2.substr(0, n - 1)));
        
        // If both last characters are different
        return 1 + mini(minDistance(word1,                  word2.substr(0, n - 1)),   // Insert 
                        minDistance(word1.substr(0, m - 1), word2),                    // Remove
                        minDistance(word1.substr(0, m - 1), word2.substr(0, n - 1))    // Replace
                       );
    }
        
    // Utility function to find minimum of three numbers
    int mini(int x, int y, int z) { return std::min(std::min(x, y), z); }
    
};
*/f
