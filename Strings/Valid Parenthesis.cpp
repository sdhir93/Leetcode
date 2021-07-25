/*
Problem: https://leetcode.com/problems/valid-parentheses/

Solution:

- Require two data structures - unordered map and stack

- Make an unordered map of characters
    - key will be closed brackets
    - vlaue will be open brackets

- Push open brackets onto stack

- If encountered anything other than open brackets,
check the current top of the stack. If the map value
matches then pop that element, else false

Time complexity : O(n)
Space complexity : O(n)
n -> size of input string
*/

class Solution
{
public:
    bool isValid(string s)
    {
        if(s.size() == 0) return true;

        // If size is not multiple of 2, not valid
        if(s.size() % 2 == 1) return false;

        // Verify that first element should not be closed bracket
        char c = s[0];

        if(c == ')' || c == '}' || c == ']' ) return false;

        unordered_map<char, char> map;

        // Map the closed brackets to open brackets
        map[')'] = '(';
        map['}'] = '{';
        map[']'] = '[';

        stack<char> st;

        // Go over all brackets in the string
        for(int i = 0; i < s.size(); i++)
        {
            char c = s[i];

            // Keep pushing open brackets on the stack
            if(c == '(' || c == '{' || c == '[' ) st.push(c);

            // Check the top element of stack and check whether it
            // matches with the value of map with current element as key
            else if(st.top() == map[c]) st.pop();

            // If we get something else, return false
            else return false;
        }

        // Check size of stack
        if(st.empty()) return true;
        else return false;
    }
};