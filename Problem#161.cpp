/*
Problem: https://leetcode.com/problems/one-edit-distance/submissions/

Solution:
- Return false if
    - both strings are equal
    - both lengths equal and differ by more than 1 chars
    - lengths differ by more than 1
- Return true if
    - lengths equal and differ by exactly 1
    - lengths differ by 1 and string 1 is subsequence of string 2
    
Time complexity:  O(n + m)
Space complexity: O(1)

*/

#include <cstdlib>
class Solution {
public:
    
    // Function to find whether shorter string is subsequence of longer string
    bool isSubsequence(string& shorter, string& longer) {
        
        // init index iterators
        int i = 0;
        int j = 0;
        
        // Traverse both strings
        for(; i < shorter.size() && j < longer.size() ; j++)
        {
            // Increment first string iterator only if both chars equal
            if(shorter[i] == longer[j]) i++;
        }
        
        // Return true if first string iterator reached end
        return i == shorter.size();
    }
    
    
    bool isOneEditDistance(string s, string t) {
        
        // Init sizes
        int size_1 = s.size();
        int size_2 = t.size();
        
        // Return false if strings are same
        if(s == t) return false;
        
        // Check if their sizes are equal
        else if (size_1 - size_2 == 0) {
            int diff = 0;
            
            int i = 0;
            int j = 0;
            
            // Traverse both and they should exactly differ by 1
            for(; i < s.size() && j < t.size();i++,j++ )
            {
                if(s[i] != t[j]) {
                    diff++;
                    if(diff > 1) return false;
                }
            }
            
            return diff == 1;
        }
        
        // Check if shorter string is subsequence of longer string
        // only if they differ by 1 in size
        else if (abs(size_1 - size_2) == 1) {
            string *longer = s.size() < t.size() ? &t : &s;
            string *shorter = s.size() < t.size() ? &s : &t;
            return isSubsequence(*shorter, *longer);
        }
        
        return false;
        
    }
};
