/*
Problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/

Solution:

- Require 1 array of 26 chars that maps index
(alphabet char converted to int) to window end

- If we encounter a char already in our map, set windowstart
as max of windowstart or 1 + window end(retreived from map)

- Set windowEnd for current char

- Update maxLength after every iteration


Time complexity : O(n)
Space complexity : O(1)
n -> size of input string
*/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int maxLength = 0;
        int windowEnd = 0;
        int windowStart = 0;
        int umap[26];

        // Go over all chars
        for(; windowEnd < s.size(); windowEnd++)
        {
            // Get char from the string at index windowEnd
            char right = s[windowEnd];
            
            // If we already encountered this char
            if(umap[right - 'a'] != 0)
            {
                // Set window start as max of windowstart and
                // 1 + windowEnd (retrieved from map)
                windowStart = max(windowStart, 1 + umap[right - 'a']);
            }
            
            // Update the map
            umap[right - 'a'] = windowEnd;

            // Update maxLength
            maxLength = max(maxLength, windowEnd - windowStart + 1);
        }
        
        return maxLength;    
    }
};
