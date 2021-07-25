/*
Problem: https://leetcode.com/problems/sort-features-by-popularity/

Solution:

- 2 Data structures:
    a. Unordered map of <string, int> to store popularity/ frequency of features
    b. unordered_set of <string> to store unique words in each response
    
- Idea is to go over al the repsonses and use istringstream to go over the words
in a each response string 
    - Use .insert(x).second to increment popularity coz popularity is unique per
    response
    - clear after processing each response via istringstream
    
- Use stable sort since we want to maintain the same order as input vector
when popularity is same

Time Complexity: O(n log n) => stable sort
Space Complexity: O(n) => unordered map


*/
class Solution {
public:
    vector<string> sortFeatures(vector<string>& feats, vector<string>& responses) {
        
        // Unordered map of <feature, frequency>
        unordered_map<string, int> popMap;
        
        // Init all popularity/ frequency to 0
        for(auto const &ref : feats)
        {
            popMap[ref] = 0;
        }
        
        // We chose unordered set since it offers unique insert using .insert(x).second
        unordered_set<string> s;
        
        // Go over al the repsonses string
        for(auto const &ref : responses)
        {
            // Use istringstream to go over the words in a each response string 
            // when popularity is same
            istringstream ss(ref);
            string word;
            while(ss >> word)
            {
                // Test if this word in stream is unique or not
                // Increase popularity if unique
                if(s.insert(word).second) popMap[word]++;
            }
            
            // Clear the set
            s.clear();
        }
        
        // Use stable sort since we want to maintain the same order as input vector
        // Third argument is custom comparator defined as lambda callable
        stable_sort(feats.begin(), feats.end(), [&](const string& a, const string& b) {
           return popMap[a] > popMap[b]; 
        });
        
        
        // Return the sorted array, this is the input array as well
        return feats;
    }
};