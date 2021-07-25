/*

https://leetcode.com/problems/complement-of-base-10-integer/

Solution :

XOR of a number with 111's (No. of 1's equal to no. of digits
in binary representation of input number) will flip all bits
and give its compliment

Time complexity : O(1)
Space complexity : O(1)

*/

class Solution {
public:
    int bitwiseComplement(int N)
    {
        // Return 1 if input is zero
        if(N == 0) return 1;

        // Get the no. of digits in binary
        // representation rounded down
        // int rounds down
        int p = log2(N);

        // Num will have all bits as 1
		int num = pow( 2, p + 1 ) - 1;

        return N^num;
    }
};