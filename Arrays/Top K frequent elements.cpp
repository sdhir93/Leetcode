/*
Problem: https://leetcode.com/problems/top-k-frequent-elements/

Solution:

The essential data structure for top K problems is a priority queue

- Require two data structures
    - Unordered map with key as element and value as frequency
    - Priority queue of pair<int, int> - min heap sorted by frequency

- Caculate frequency of integers using unordered map

- For each (key, value) pair in the map, keep pushing into minheap
and when size K is exceeded, remove the top element of heap

- Transfer all the first value of the pair in minheap to a result vector

Time complexity : O(n) + O(n * Logk) = 0(n * Logk)
    - O(n) for calculating frequency
    - O(n * Logk) for pushing into minheap

Space complexity : O(n) + 2*O(k) = O(n)

n -> size of input vector
*/

class Solution
{
private:


public:

    // Comparator for creating the priority queue
    struct compare
    {
        bool operator()(const pair<int, int> &x, const pair<int, int> &y)
        {
            // Create minheap for this problem by
            // sorting by frequency (second of the pair)
            return x.second > y.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        // Unordered map for storing frequency values
        unordered_map<int, int> freqmap;
        for(int n : nums) freqmap[n]++;

        // Create minheap by pairing the (key, value)
        // The second argument is always a vector of first argument type
        // Third argument is custom comparator to denote how we want the
        // priority queue to be ordered
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> minheap;

        // Go over all elements in frequency map
        for(auto entry : freqmap)
        {
            // Push the (key, value) pairs into the minheap
            // Logk insert, k is size of priority queue
            minheap.push(entry);

            // Pop the smallest element if size exceeds
            if(minheap.size() > k) minheap.pop();
        }

        // Result vector to store first elements from minheap
        vector<int> top;

        // Transfer min heap to topNumbers
        while (!minheap.empty())
        {
          top.push_back(minheap.top().first);
          minheap.pop();
        }

        return top;
    }
};
