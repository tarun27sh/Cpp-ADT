/*
TODO This queue implementation doesn't grow.
User defines a new queue object and passes the size
In order to make it dynamic, use realloc if the size limit 
is reached.
*/


#include <iostream>
 
using namespace std;

class Queue {
    public:
        // default constructor
        Queue();

        // param constructor
        Queue(int);

        // Returns whether the queue is empty
        bool empty();

        // Returns the number of elements in the queue.
        int size();

        // Returns a reference to the front most element
        int front();

        // Returns a reference to the last element
        int back();

        // Inserts a new element at the end of the queue
        bool enqueue(int);

        // Removes the element on front of the queue
        int dequeue();

        // print queue
        void print();
    private:
        int* queue;
        int queueSize;
        int noOfItems;
        int head;
        int tail;
};
