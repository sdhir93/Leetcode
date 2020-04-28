/*

Problem: https://leetcode.com/problems/reverse-integer/

Solution:

- Mulitply the reverse by 10 and add number%10
- Divide number by 10

Time complexity : O(n)
Space complexity : O(1)
n -> number of digits in the decimal representation of input number
*/

class Solution {
public:
    int reverse(int x)
    {
        int number = x;
        int reverse = 0;
        if(x == 0) return x;

        while(number)
        {
            // Check for over flow
            if(reverse > INT_MAX/10) return 0;

            // Check for underflow
            if(reverse < INT_MIN/10) return 0;

            // Mulitply the reverse by 10 and add number%10
            reverse = reverse*10 + number%10;

            // Destroy last digit of the input number
            number = number/10;
        }

        return reverse;
    }
};