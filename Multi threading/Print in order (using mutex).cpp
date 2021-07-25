/*

Problem : https://leetcode.com/problems/print-in-order/

Solution :

- Use a mutex, condition variable and an integer i that
is incremented after executing one thread

Time complexity : O(1)
Space complexity : O(1)
No dependence on input, time complexity may be depending on number
of threads (revisit later maybe)

*/
class Foo
{
private:
    condition_variable cv; // For wait and notify
    mutex m;               // To synchronize the access
    int i = 1;             // Wait condition

public:

    void first(function<void()> printFirst)
    {
        printFirst();

        // Increment so that next thread can meet condition
        i++;

        // Notify if other threads waiting
        cv.notify_all();
    }

    void second(function<void()> printSecond)
    {
        // Wrap the mutex using unique lock
        // because unique lock can be unlocked
        // by condition variable
        std::unique_lock<std::mutex> lk(m);

        // Condition variable to be used only after acquiring lock
        cv.wait(lk, [&]{ return i == 2;});

        printSecond();
        i++;
        cv.notify_all();
    }

    void third(function<void()> printThird)
    {
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, [&]{ return i == 3;});

        printThird();
        i++;
        cv.notify_all();
    }
};