/*

Problem : https://leetcode.com/problems/first-unique-character-in-a-string/

Solution :

- Calculate frequency of all chars

- Return index of character with frequency 1

Time complexity : O(n)
Space complexity : O(1)
n -> size of input string

*/
class Solution {
public:
    int firstUniqChar(string& s)
    {
        // Initialize a vector of 26 to
        // stor frequencies of a - z
        vector<int> count(26, 0);

        // Increment the count[i] for
        // each char encountered
        for(const char c: s) count[c - 'a']++;

        // Go over all chars to check whose
        // frequency is 1 i.e. unique
        for(int i = 0; i < s.size(); i++)
            if(count[s[i]-'a'] == 1) return i;

        return -1;
    }
};
