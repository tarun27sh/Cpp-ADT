/*
This stack implementation doesn't grow.
User defines a new stack object and passes the size
In order to make it dynamic, use realloc if the size limit 
is reached.
*/


#include <iostream>
 
using namespace std;

class Stack {
    public:
        // default constructor
        Stack();

        // param constructor
        Stack(int);

        // Returns whether the stack is empty
        bool empty();

        // Returns the number of elements in the stack.
        int size();

        // Returns a reference to the top element in the stack. 
        int top();

        // Inserts a new element at the top of the stack
        bool push(int);

        // Removes the element on top of the stack
        int pop();

        // print stack
        void print();
    private:
        int* stack;
        int stackSize;
        int noOfItems;
};
