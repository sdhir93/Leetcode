/*
Problem: https://leetcode.com/problems/sort-array-by-increasing-frequency/

Solution:


- For these type of questions, 2 data structures are required
    1. unordered map <element, frequency>
    2. vector<pair<element, frequency>>
- Store the frequency of ints in an unordered_map
- Pour the items from map to a vector of pair<int, int>
- Sort with a custom comparator
- Pour the result ints into a vector and return

Time Complexity: O(n log n)
Space Complexity: O(n)

*/
class Solution {
private:
    
    // Custom comparator in decreasing order of frequency
    static bool myCmp(const pair<int, int>& a, const pair<int, int>& b)
    {
        if(a.second == b.second) return a > b;
        return a.second < b.second;
    }
    
public:
    vector<int> frequencySort(vector<int>& nums) {
        
        // Unordered map <element, freq>
        unordered_map<int, int> umap;
        
        // Fill the map
        for(auto num : nums)
        {
            umap[num]++;
        }
        
        vector<pair<int, int>> sortedAnswer;
        
        // Go over elements in map and store in a sorted answer
        for(auto it: umap)
        {
            sortedAnswer.push_back({it.first, it.second});
        }
        
        // Sort with custom comparator
        sort(sortedAnswer.begin(), sortedAnswer.end(), myCmp);
        
        vector<int> answer;
        
        // Pour the results from sortedAnswer to result
        for(auto it: sortedAnswer)
        {
            int freq = it.second;
            
            // For 'freq' times, fill the same element
            while(freq--) answer.push_back(it.first);
        }
        
        return answer;
    }
};