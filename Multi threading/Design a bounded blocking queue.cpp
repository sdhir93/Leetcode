/*

Problem : https://leetcode.com/problems/design-bounded-blocking-queue/

Solution :

- Use mutex lock and 2 condition variables
- Notify only if there are waitingReaders or waitingWriters

Time complexity : O(1) for both enqueue and dequeue
Space complexity : O(n)
n -> input capacity

*/
class BoundedBlockingQueue
{
private:

    mutex mtx;                      // Lock to synchronize access to the shared queue
    condition_variable itemRemoved; // Wait/notify if something is removed
    condition_variable itemAdded;   // Wait/notify if something is added
    queue<int> q;                   // Internal queue to add and pop items
    int capacityQ;                  // Capacity set by constructor/client
    int waitingReaders;             // No. of threads waiting to dequeue
    int waitingWriters;             // No. of threads waiting to enqueue

public:

    // Default constructor that sets capacity
    // and waiting threads
    BoundedBlockingQueue(int capacity)
    {
        capacityQ = capacity;
        waitingReaders = 0;
        waitingWriters = 0;
    }

    void enqueue(int element)
    {
        // Acquire the lock and release via RAII
        unique_lock<mutex> lck(mtx);

        // The wait is always wrapped inside a
        // while loop to avoid spurious wake ups
        while(q.size() == capacityQ)
        {
            waitingWriters++;
            itemRemoved.wait(lck);
            waitingWriters--;
        }

        // Store the element
        q.push(element);

        // Notify only if there are waiting reader threads
        if(waitingReaders)
        {
            itemAdded.notify_one();
        }
    }

    int dequeue()
    {
        // Acquire the lock and release via RAII
        unique_lock<mutex> lck(mtx);

        // The wait is always wrapped inside a
        // while loop to avoid spurious wake ups
        while(q.empty())
        {
            waitingReaders++;
            itemAdded.wait(lck);
            waitingReaders--;
        }

        // Get the item and remove
        int item = q.front();
        q.pop();

        // Notify only if there are waiting writer threads
        if(waitingWriters)
        {
            itemRemoved.notify_one();
        }

        return item;
    }

    int size()
    {
        // Acquire the lock and release via RAII
        lock_guard<mutex> lck(mtx);
        return q.size();
    }
};