/*

Problem: https://leetcode.com/problems/palindrome-number/

Solution:

- Make a local copy temp of the input integer and have a unsigned long int
as the reverse number = 0

- In a while loop that tests condition temp!=0
    - Mulitply current reverse by 10
    - Add the temp % 10 to reverse
    - Divide temp by 10

- Check if both equal

Time complexity : O(n)
Space complexity : O(1)
n -> number of digits in the decimal representation of input number
*/

class Solution
{
public:
    bool isPalindrome(int x)
    {
        // Return false if inout is less than 0
        if(x < 0) return false;

        // Have a local copy of x for comparison later
        int temp = x;

        // unsigned long int to watch for overflows
        unsigned long int reverse = 0;

        while (temp)
        {
            // Self multiply reverse by 10
            reverse *= 10;

            // Add the last digit of temp to reverse
            // Gets multiplied by 10 in next iteration
            reverse += temp % 10;

            // Remove last digit of temp
            temp /= 10;
        }

        return x == reverse;
    }
};