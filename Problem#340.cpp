/*

Problem : https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

Solution :

- This is a sliding window problem
  [windowStart, windowEnd]

- Store the frequency of character found at windowEnd

- Calculate maxLength

- When we reach size k, shrink the window start by removing left most character

- Calculate maxLength

Time complexity : O(n)
Space complexity : O(k)
n -> size of input string
k -> number of distinct characters

*/
class Solution
{
public:
    int lengthOfLongestSubstringKDistinct(string str, int k)
    {
        // Initiliaze windowStart index and maxLength
        int windowStart = 0;
        int maxLength = 0;

        // Create an unordered map of char to int
        // to store frequency of char
        unordered_map<char, int> charFrequencyMap;

        // Extend the range [windowStart, windowEnd]
        for (int windowEnd = 0; windowEnd < str.length(); windowEnd++)
        {
            // Get the rightmost char i.e. new char
            // from the windowEnd index
            char rightChar = str[windowEnd];

            // Increment its frequency
            charFrequencyMap[rightChar]++;

            // Shrink the sliding window, until we are left with 'k'
            // distinct characters in the frequency map
            while (charFrequencyMap.size() > k)
            {
                // Get the leftmost character
                // using the windowStart index
                char leftChar = str[windowStart];

                // Decrement its frequency
                charFrequencyMap[leftChar]--;

                // Check if size becomes 0
                if (charFrequencyMap[leftChar] == 0)
                {
                    // Remove from the map
                    charFrequencyMap.erase(leftChar);
                }

                // Shrink the window
                windowStart++;
            }

            // remember the maximum length so far
            maxLength = max(maxLength, windowEnd - windowStart + 1);
        }

        return maxLength;
    }
};
