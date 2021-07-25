/*
Problem: https://leetcode.com/problems/min-stack/

Solution:

- Make a stack of a pair of two ints

- First int stores element, second int stores minimum
encountered till that element

Time complexity : O(1)
Space complexity : O(n)
n -> numbers pushed on the stack
*/

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

class MinStack
{
private:

    // 1st int is value of element and 2nd min till that operation
    stack<pair<int,int>> st;

public:

    MinStack() { }

    void push(int x)
    {
        // Push first element if stack is empty
        if(st.empty()) st.push(make_pair(x,x));

        else
        {
            // Find the minimum
            int mn = min( st.top().second, x);

            // Make a pair and push on the stack
            st.push(make_pair(x, mn));
        }
    }

    void pop() st.pop();

    int top() return st.top().first;

    int getMin() return st.top().second;
};
