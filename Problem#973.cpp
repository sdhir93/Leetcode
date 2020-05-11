/*

Problem : https://leetcode.com/problems/k-closest-points-to-origin/

Solution :

- Make a priority queue, which is by default a max heap
- Push the distance and the pair of x,y coordinates
and farthest distance will automatically be the top most element
- Remove top whenever size reaches k

Time complexity : O(n)
Space complexity : O(k)
n -> size of input vector
k -> input k value
*/


class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        // Create the result vector
        vector<vector<int>> ans;

        // If input vector is empty return
        if(points.size() == 0) return ans;

        // Make a priority queue
        priority_queue<pair<int,pair<int,int>>> pq;

        // Go over all the points
        for(int i = 0; i < points.size(); i++)
        {
            // Calculate distance
            int dist=points[i][0]*points[i][0]+points[i][1]*points[i][1];

            // If size has not reached k
            if(pq.size()<k)
            pq.push( { dist, { points[i][0], points[i][1] } } );

            // If size reached k
            else
            {
                // Check distance of top
                if(dist < pq.top().first)
                {
                    // Pop out top
                    pq.pop();

                    // Push the current point
                    pq.push( { dist, { points[i][0],points[i][1] } } );
                }
            }
        }

        // If queue is not empty
        while(!pq.empty())
        {
            // Store the answer is result vector
            ans.push_back( { pq.top().second.first, pq.top().second.second } );
            pq.pop();
        }

        return ans;
    }

};