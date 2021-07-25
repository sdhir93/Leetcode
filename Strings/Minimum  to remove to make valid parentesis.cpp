/*

Problem: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

Solution:

- Simply maintain a stack of indices when we encounter
a open bracket and pop that out whe we get a matching
closing bracket only if current top is opening

- If not store the index in stack and at the end remove that
from the string using erase

- This way invalid closed bracket and invalid open bracket both
indices remain on the stack

Time complexity : O(n)
Space complexity : O(n)
n -> size of input string
*/

class Solution
{
public:
    string minRemoveToMakeValid(string inputStr)
    {
        // Create a stack
        stack<int> s;

        // Go over all the string elements
        for(int i = 0; i < inputStr.length(); i++)
        {
            // Get the current char
            char currentChar = inputStr[i];

            // Push on stack if open bracket
            if(currentChar == '(')
            {
                s.push(i);
                continue;
            }

            // Closing bracket
            else if(currentChar==')')
            {
                // Check current top
                if(!s.empty() and inputStr[s.top()] == '(')
                {
                    // Pop if condition met and continue
                    s.pop();
                    continue;
                }

                // Mark as invalid
                else s.push(i);
            }
        }

        // Stack now contains invalid brackets
        while(!s.empty())
        {
            // Get the index
            int index = s.top();

            // Pop it out
            s.pop();

            // Erase that index from string
            inputStr.erase(index, 1);
        }

        return inputStr;
    }
};