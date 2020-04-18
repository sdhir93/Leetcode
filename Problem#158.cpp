/*
Problem: https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/

Solution:

- Since read(...) can be called multiple times, three things need to be saved:
the char elements read previously in the buffer, the previous buffer size and
the previous buffer index i.e. these can be made private.

- When previous buffer index wraps around i.e. becomes zero, fetch more
characters

- Break when buffer size is 0 or when required no. of characters have been read

- In between, keep copying the char elements from buf4 to the destination buffer

Time complexity : O(n)
Space complexity : O(1)
n -> number of characters to read
*/
class Solution
{
private:
    int buffer4Index = 0;   // Buffer4 index that persists between calls
    char buffer4[4];        // Buffer of 4 char elements
    int bufferSize = 0;     // Size of buffer returned by read4

public:
    int read(char *buf, int n)
    {
        // index for destination buffer
        int totalRead = 0;

        while(totalRead != n)
        {
            // If buffer4 index is 0, fetch
            // more characters into buffer4
            if(buffer4Index == 0) bufferSize = read4(buffer4);

            // If buffer size returned above is 0, break
            if(bufferSize == 0) break;

            // Copy char elements from buffer to destination
            // and advance the destination buffer index
            buf[totalRead++] = buffer4[buffer4Index];

            // Advance the buffer4 index
            buffer4Index = (buffer4Index + 1) % bufferSize;
        }

        return totalRead;
    }
};