/*

Problem : https://leetcode.com/problems/find-the-town-judge/

Solution :

Source : https://leetcode.com/problems/find-the-town-judge/solution/

- Outdegree of a vertex (person) is the number of directed edges
going out of it. For this graph, the outdegree of the vertex
represents the number of other people that person trusts

- Likewise, we say that the indegree of a vertex (person) is the
number of directed edges going into it. So here, it represents
the number of people trusted by that person.

- Problem simplifies to calculating the indegree and outdegree
for each person and then checking whether or not any of them meet
the criteria of the town judge.

- We can instead build a single Array with the result of
indegree - outdegree for each person. In other words, we'll
+1 to their "score" for each person they are trusted by, and
-1 from their "score" for each person they trust. Therefore,
for a person to maximize their "score", they should be trusted
by as many people as possible, and trust as few people as possible.

Time Complexity : O(e)
Space Complexity : O(n)
e -> number of edges, trust relationships
n -> input N

*/
class Solution
{
public:
    int findJudge(int N, vector<vector<int>>& trust)
    {
        // Size of input vector should ne atleast
        // N - 1
        if(trust.size() < N -1) return -1;

        // Initiliaze vector to store trustScores
        vector<int> trustScores(N + 1);

        // Go over all the relationships
        // and store indegree and outdegree
        // that eventually become trustscores
        for(vector<int> i : trust)
        {
            trustScores[i[0]]--;
            trustScores[i[1]]++;
        }

        // Check for town judge
        // He is the one with trustScore N - 1
        for (int i = 1; i <= N; i++)
        {
            if (trustScores[i] == N - 1) return i;
        }

        return -1;
    }
};