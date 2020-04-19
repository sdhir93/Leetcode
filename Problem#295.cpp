/*
Problem: https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/

Solution:

- Data Structure required - priority queues so that it is easy to
maintain direct access to median elements at all times. The median
would take a constant amount of time.

- Keeping the entire input sorted is not a requirement.

Time complexity : O(logn)
Space complexity : O(n)
n -> number of input integers
*/

class MedianFinder
{
private:

    priority_queue<int> maxHeap; // max heap that will store the smaller elements
    priority_queue<int, vector<int>, greater<int>> minHeap; // min heap that stores the bigger elements

public:

    void addNum(int num)
    {
        minHeap.push(num);

        // Balancing step
        maxHeap.push(minHeap.top());

        minHeap.pop();

        while(minHeap.size() < maxHeap.size())
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }

    double findMedian()
    {
        // Check size of both heaps
        if (maxHeap.size() == minHeap.size()) return (maxHeap.top() + minHeap.top()) / 2.0;
        else return minHeap.top();
    }
};