/*
Problem: https://leetcode.com/problems/single-number/

Solution: XOR of a number with itself is 0
          0 XOR number = number
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int accumulator=0;
        for(auto x : nums) {
            accumulator ^= x;
        }
        return accumulator;
    }
};