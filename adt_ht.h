/*
    - This hashtable implementation has a fixed user defined size
    - Makes use of array & ll.
    - each array entry contains a linkedList
    - hashing function coverts a large input to a no within array range by mod'ing(%size)
    - size should be a prime no in order to minimize collisions
*/


#include <iostream>
 
using namespace std;

typedef struct node {
    int   val;
    int   key;
    node* next;
}node;

typedef struct bucket {
    node*   head;
    int     size;
}bucket;

class HashTable {
    public:
        // default constructor
        HashTable();

        // parameterized constructor
        HashTable(int);

        // Returns whether the queue is empty
        bool empty();

        // Returns the number of elements in the queue.
        int size();

        // Returns a reference to the front most element
        int front();

        // Returns a reference to the last element
        int back();

        // Inserts a new element at the end of the queue
        bool insert(int, int);

        // Removes the element on front of the queue
        int remove(int, int);

        // Removes the element on front of the queue
        int lookup(int);

        // print queue
        void print();

        // hash
        int hash(int);
    private:
        int noOfItems;
        int noOfBuckets;
        bucket *ht;
};
