/*
https://leetcode.com/problems/rotate-image/

Rotate Image

- Swap ij
- Reverse all rows 

*/
class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n = m.size() ;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(m[i][j], m[j][i]);
            }
        }
        
        for(int i = 0; i < n; i++) {
             reverse(m[i].begin(), m[i].end()) ;
        }
    }
};