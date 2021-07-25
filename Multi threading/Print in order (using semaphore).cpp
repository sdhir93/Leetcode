/*

Problem : https://leetcode.com/problems/print-in-order/

Solution :

- Use semaphore to signal when one function is done
- Disadvantage : does not scale if many threads and tasks

Time complexity : O(1)
Space complexity : O(1)
No dependence on input, time complexity may be depending on number
of threads (revisit later maybe)

*/
#include <semaphore.h>

class Foo {

protected:
    sem_t firstJobDone;  // Signals when first job done
    sem_t secondJobDone; // Signals when second job done

public:

    Foo()
    {
        // Initialize semaphore
        sem_init(&firstJobDone, 0, 0);
        sem_init(&secondJobDone, 0, 0);
    }

    void first(function<void()> printFirst)
    {
        printFirst();

        // Post/ signal that work was done
        sem_post(&firstJobDone);
    }

    void second(function<void()> printSecond)
    {
        // Wait on first job
        sem_wait(&firstJobDone);
        printSecond();

        // Post/ signal that work was done
        sem_post(&secondJobDone);

    }

    void third(function<void()> printThird)
    {
        // Wait on second job
        sem_wait(&secondJobDone);
        printThird();
    }
};