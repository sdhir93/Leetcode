/*
Problem: https://leetcode.com/problems/read-n-characters-given-read4/

Solution:

- Read chaacters into buffer4
- copy the elements into destination buffer depending on
number of characters read

Time complexity : O(n)
Space complexity : O(1)
n -> number of characters to read

The read4 API is defined in the parent class Reader4.
int read4(char *buf);

*/

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */

    int read(char * buf, int n)
    {
        char buffer4[4];

        // Go over all index upto n
        for(int index = 0; index < n;)
        {
            // Read characters into buffer4
            int currentReads = read4(buffer4);

            // If reading complete, end the string and break
            if(currentReads == 0)
            {
                buf[index] = '\0';
                break;
            }

            // Copy elements from buffer4 into destination buffer
            for(int  i = 0; i < currentReads; i++)
            {
                buf[index++] = buffer4[i];
            }
        }

        return n;
    }
};