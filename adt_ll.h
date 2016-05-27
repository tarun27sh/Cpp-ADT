/*
User defines a new queue object and passes the size
*/


#include <iostream>
 
using namespace std;

typedef struct node {
    int   val;
    node* next;
}node;

class LinkedList {
    public:
        // default constructor
        LinkedList();

        // Returns whether the queue is empty
        bool empty();

        // Returns the number of elements in the queue.
        int size();

        // Returns a reference to the front most element
        int front();

        // Returns a reference to the last element
        int back();

        // Inserts a new element at the end of the queue
        bool insert(int);

        // Removes the element on front of the queue
        int remove(int);

        // Removes the element on front of the queue
        int lookup(int);

        // print queue
        void print();
    private:
        int noOfItems;
        node *head;
};
