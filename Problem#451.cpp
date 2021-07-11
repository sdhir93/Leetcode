/*
Problem: https://leetcode.com/problems/sort-characters-by-frequency/

Solution:

- For these type of questions, 2 data structures are required
    1. unordered map <element, frequency>
    2. vector<pair<element, frequency>>
- Store the frequency of chars in an unordered_map
- Pour the items from map to a vector of pair<char, int>
- Sort with a cusotm comparator
- Pour the result chars into a string and return

Time Complexity: O(nlog n)
Space Complexity: O(n)

*/
class Solution {
public:
    
    // Custom comparator in decreasing order of frequency
    static bool myCmp(const pair<char, int>& a, const pair<char, int>& b)
    {
        return a.second > b.second;
    }
    
    string frequencySort(string s) {
        
        // Unordered map <element, freq>
        unordered_map<char, int> umap;
        
        // Fill the map
        for(char c : s)
        {
            umap[c]++;
        }
        
        vector<pair<char, int>> sortedAnswer;
        
        // Go over elements in map and store in a sorted answer
        for(auto c : umap) {
            sortedAnswer.push_back({c.first, c.second});
        }
        
        // Sort with custom comparator
        sort(sortedAnswer.begin(), sortedAnswer.end(), myCmp);
        
        string answer;
        
        // Pour the results from sortedAnswer to result
        for(auto it: sortedAnswer)
        {
            int freq = it.second;
            
            // For 'freq' times, fill the same element
            while(freq--) answer += it.first;
        }
        
        return answer;
        
    }
};