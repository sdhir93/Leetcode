/*
Problem: https://leetcode.com/problems/is-subsequence/

Solution

- Traverse through both strings
- Increment the first string only if both characters match
- Return true if index of first string mactches with its length

Time complexity: O(n)
Space complexity: O(1)

*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        // Check if both strings are equal
        if(s == t) return true;
        
        // Init index iterators
        int i = 0;
        int j = 0;
        
        // Traverse both strings
        for(; i < s.size() && j < t.size(); j++)
        {
            // Increment first string's iterator only if there is a match
            if(s[i] == t[j]) i++;
        }
        
        // Return true if index and size matches for first string
        return  i == s.size();
        
    }
};
