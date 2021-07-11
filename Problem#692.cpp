/*
Problem : https://leetcode.com/problems/top-k-frequent-words/

Solution:

- Three data structures
    1. Frequency map <string, int>
    2. vector of pair <string, int>
    3. vector <string> => result
    
- Sort the vector with a custom comparator based on the given 2 requirements
    - descending order of frequency
    - if same frequency, in lower to higher alphabetical order

- Pour the elements from 2nd data structure to 3rd

- Resize the resultant vector to k and return

        
*/class Solution {
private:
    
    // Custom comparator
    static bool myCmp(const pair<string, int>& a, const pair<string, int>& b)
    {
        if(a.second == b.second) return a.first < b.first;
        else return a.second > b.second;            
    }

    
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        // Frequency map
        unordered_map<string, int> freqMap;
        for(auto word: words)
        {
            freqMap[word]++;
        }
        
        // Sorted answer of pair of string, frequency
        vector<pair<string, int>> sortedAnswer;
        
        // Push elements into the vector
        for(auto word: freqMap)
        {
            
            sortedAnswer.push_back({word.first, word.second});
        }

        // Sort the vector with custom comparator
        sort(sortedAnswer.begin(), sortedAnswer.end(), myCmp);

        vector<string> result;
        
        // Pour elements into result vector
        for(auto it : sortedAnswer)
        {
            result.push_back(it.first);
        }
        
        // Resize result to k
        result.resize(k);
        
        return result;
    }
};