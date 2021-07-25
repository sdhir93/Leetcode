/*
Problem: https://leetcode.com/problems/occurrences-after-bigram/

Occurrences After Bigram

- Use stringstream to parse the text string

- Save prev 1 and prev 2

- Save the current into vector

TC: O(n) 
SC: O(1)
n -> length of text string

*/
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {    
        vector<string> result;
        stringstream ss(text);
        
        // prev2 prev1 curr
        string prev1 = "";
        string prev2 = "";
        string curr  = "";
        
        // Go through all words in string stream
        while(ss >> curr) {
            
            // If sequence of words found, then store the curr
            // result vector
            if(prev2 == first && prev1 == second) {
                result.push_back(curr);
            }
            
            //           prev 2 -> prev 1 -> curr(from ss)
            // prev 2 -> prev 1 -> curr
            prev2 = prev1;
            prev1 = curr;
        }
        
        return result;
    }
};