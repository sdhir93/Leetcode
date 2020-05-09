/*

Problem : https://leetcode.com/problems/valid-perfect-square/submissions/

Solution :

- Use Newton's Algorithm that starts with num / 2
as seed and goes to tangent

Time complexity : O(logn)
Space complexity : O(1)
n -> input number

*/

class Solution {
public:
    bool isPerfectSquare(int num)
    {
        // Return true if 0 or 1
        if (num < 2) return true;

        // Init long x as num/2 - this is seed
        // for the guess
        long x = num / 2;

        // Newton's Algorithm, goes to tangent
        while (x * x > num)
        {
            // Make next guess, by approximating
            // by its tangent line
            x = (x + (num / x) ) / 2;
        }

        return (x * x == num);
    }
};