#include <iostream>
#define LOG(x) std::cout << x << std::endl;
#define MAX_QUEUE_SIZE 10

class Queue
{
private:
    int _arr[MAX_QUEUE_SIZE];
    int HEAD = -1, TAIL = -1;
public:
    void enQueue(int x)
    {
        if((TAIL + 1) % MAX_QUEUE_SIZE == HEAD)
        {
            LOG("Limit reached");
            return;
        }
        else if(isEmpty())
        {
            HEAD = TAIL = 0;
        }
        else
        {
            TAIL = (TAIL + 1) % MAX_QUEUE_SIZE;
        }
        _arr[TAIL] = x;
    }
    void deQueue()
    {
        if(isEmpty())
        {
            LOG("Empty Queue. No removals");
        }
        else if(HEAD == TAIL)
        {
            HEAD = TAIL = -1;
        }
        else
        {
            HEAD = (HEAD + 1) % MAX_QUEUE_SIZE;
        }
    }
    int front()
    {
        return _arr[HEAD];
    }
    bool isEmpty()
    {
        return (HEAD == -1 && TAIL == -1);
    }
    void printQueue()
    {
        for (int i = HEAD ; i != TAIL; i = (i + 1) % MAX_QUEUE_SIZE)
        {
            LOG(_arr[i]);
        }   
        LOG(_arr[TAIL]);     
    }
};

int main()
{
    Queue Q;
    // Q.enQueue(1);
    // Q.enQueue(2);
    // Q.enQueue(3);
    // Q.enQueue(4);
    // Q.enQueue(5);
    // Q.enQueue(6);
    // Q.enQueue(7);
    // Q.enQueue(8);

    Q.deQueue();
    // Q.deQueue();
    // Q.deQueue();
    // Q.deQueue();

    // Q.enQueue(9);
    // Q.enQueue(10);
    // Q.enQueue(11);
    // Q.enQueue(12);
    // Q.enQueue(13);
    // Q.enQueue(14);
    // Q.enQueue(15);


    Q.printQueue();

    // while(!Q.isEmpty())
    // {
    //     LOG(Q.front());
    //     Q.deQueue();
    // }

    return 0;
}