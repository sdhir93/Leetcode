/*
Problem: https://leetcode.com/problems/word-break/submissions/

Solution:

- Two data structures
1. Unordered set of string to optimize the find operation
2. dp array of bool to return the answer

- Divide and conquer
 - Consider string length is starting from i = 1
 - Find whether a substr (j = i - 1, i - j) is present in set or not
 - Set the true if yes

- Return dp[word.size()]

Time Complexity: O(n + n*l) => O(n(1 + l)) => O(n * l)
Space Complexity: O(l) => l is word size and n is size of dictionary

*/
class Solution {
public:
    bool wordBreak(string word, vector<string>& dict)
    {
        // O(n) vs O(n logn) in set
        // set<string> s(dict.begin(), dict.end());
        // But unordered set does this at cost of space
        unordered_set<string> s(dict.begin(), dict.end());
        
        // Dp array of bools
        vector<bool> dp(word.size() + 1, false);
        
        // Set 0th index as true because we can definitely break empty string
        dp[0] = true;
        
        // O(l)
        for(int i = 1; i <= word.size(); i++)
        {
            for(int j = i - 1; j >= 0; j--)
            {
                // Time complexity for find method for unordered set in
                // Average case is O(1)
                // Worst complexity is O(n)
                // vs Set whose complexity will be O(log n)
                
                // Check if previous result is TRUE(means that we can break the string at previous index
                if(s.find(word.substr(j, i - j)) != s.end() && dp[j])
                {
                    dp[i] = true;
                    
                    // early break since at least one word can break the string
                    break;
                }
            }
        }
        
        return dp[word.length()];
    }
    
};