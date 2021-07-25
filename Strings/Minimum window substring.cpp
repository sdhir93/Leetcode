/*
Problem: https://leetcode.com/problems/minimum-window-substring/

Solution Source: https://leetcode.com/problems/minimum-window-substring/discuss/1309852/C%2B%2B-or-Sliding-Window-or-EXPLAINED

I modified with some optimizations

Solution:
- Require two frequency maps
    - one for each strings

- Edge cases
    - equal strings - return any string
    - empty strings - return ""
    - supposedly smaller string actually bigger than other string - return ""
    
- Fill the smaller string's frequncy map

- Get required number of unique characters by getting the smaller string's
frequency map

- Init left and right pointers to 0 to iterate through larger string
ans fill its frequency map

- Whenever a character's frequecy in both maps is equal, increment found

- While found == required
    - try to shrink the window
    - first save the answer
    - answer = s.substr(l, r - l + 1);
    - shrink the window from left
    - If frequency in larger string becomes less than frequency in smaller string
        - decrement found
    - l++

- Return the answer


Time Complexity: O(n)
Space Complexity: O(n)
n ->size of string s

*/

class Solution {
public:
  string minWindow(string s, string t) {
    // If both strings equal, return any string
    if (s==t)
      	return s;
    
    // If either string is empty or if string 't' is larger
    // return empty
    if(s.length() == 0  || t.length() == 0 || t.size()> s.size()){
      	return "";
    }
    
    // Frequency map of characters in string t
    unordered_map<char, int> freqMap;
    for(int i = 0; i < t.size(); i++) {
		freqMap[t[i]]++;
    }
    
    // Size of frequency map i.e. unique characters
    int required = freqMap.size();
    
    // Left and Right pointer for the sliding window
    int l = 0, r = 0;
    
    // unique chars found in the window with their desired frequency
    int found = 0;
    
    // FreqMap of all the unique characters in the current window.
    unordered_map<char, int> windowFreqMap;
    
    string ans = "";
    
    while(r < s.length()){
		// Update the frquency of the current character in the window.
		windowFreqMap[s[r]]++;

		// If the frequency of the current character added equals to the
		// desired count in t then increment the formed count by 1.
		if(windowFreqMap[s[r]] == freqMap[s[r]]) found++;

		// Try and contract the window to get the minimum length ... till the point where it ceases to be 'desirable'.
		while (l<=r && found == required) {
			  
			// Save the smallest window until now.
			if(ans == "" || (r - l + 1) < ans.size() ) {
			    ans = s.substr(l, r-l+1);
			}

			// The character at the position pointed by the
			// `Left` pointer is no longer a part of the window.
			windowFreqMap[s[l]]--;

			if(windowFreqMap[s[l]] < freqMap[s[l]] ) {
			    found--;
			}

			l++;
		}
		r++;
    }
    
    return ans;
  }
};

