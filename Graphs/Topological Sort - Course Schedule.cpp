/*
Problem : https://leetcode.com/problems/course-schedule-ii/

Topological Sort of Directed Acyclic Graph : Course Schedule 2

Solution:

- Perform topological sort on the graph
 - Use DDFS + Stack + memoization
 - DFS - Depth First search of all the nodes
    - when we reach a node that does not have any out edges, push on the stack
    - mark it as visited
    - and perform dfs on next node

- Convert the given graph into matrix

- Also check for cycle

TC: O(V + E)
SC: O(n)

*/
class Solution {
    // Graph coloring: 0->not visited...1->visited...2->visited & processed
    bool detectCycle_util(vector<vector<int>>& adj, vector<int>& visited, int v)
    {
        if(visited[v] == 1)
            return true;
        if(visited[v] == 2)
            return false;
        
        visited[v] = 1; // Mark current as visited
        for(int i = 0; i < adj[v].size(); ++i)
            if(detectCycle_util(adj, visited, adj[v][i]))
                return true;
        
        visited[v] = 2;   // Mark current node as processed
        return false;
    }
    
    // Cycle detection
    bool detectCycle(vector<vector<int>>& adj,int n)
    {
        vector<int> visited(n,0);
        for(int i = 0; i < n; ++i)
            if(visited[i] == false)
                if(detectCycle_util(adj, visited, i))
                    return true;
        return false;
    }
    
    // Topological sort
    void dfs(vector<vector<int>>& adj, int v, vector<bool>& visited, stack<int>& mystack)
    {
        // Mark as visited
        visited[v] = true;
        for(int i = 0; i < adj[v].size(); ++i)
            if(visited[adj[v][i]] == false)
                dfs(adj, adj[v][i], visited, mystack);
        
        // Push to stack when there is no out edge left or
        // all edges have been visited
        mystack.push(v);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        // Get the size of the input prerequisites vector
        int sizeVec = prerequisites.size();
        
        // Build a adjacency matrix
        vector<vector<int>> adj(numCourses);
        
        for(int i = 0; i < sizeVec; ++i) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int> ans;
        
        // Cycle detection
        if(detectCycle(adj, numCourses))
            return ans;        
        
        // Stack for storing the vertices starting with
        // the ones whose outedges have been visited
        stack<int> mystack;
        
        // Vector of bool for memoization of visited vertices
        vector<bool> visited(numCourses, false);
        
        // Perform DFS
        for(int i = 0; i < numCourses; ++i)
            if(visited[i] == false)
                dfs(adj, i, visited, mystack);
        
        // Pour elements from stack into the vector
        while(!mystack.empty())
        {
            ans.push_back(mystack.top());
            mystack.pop();
        }
        
        return ans;
    }
};