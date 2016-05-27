/*
*/


#include <iostream>
 
using namespace std;

class Heap {
    public:
        // default constructor
        Heap();

        // parameterized constructor
        Heap(int);

        // Returns whether the heap is empty
        bool empty();

        // Returns the number of elements in the heap.
        int size();

        // Returns the minimum element in the heap
        int minimum();

        // Inserts a new element in the tree
        bool insert(int);

        // Removes the element from the tree and RET
        bool extractMin(void);

        // heapify after insert
        void heapify_after_insert(void);

        // heapify after remove
        void heapify_after_remove(void);

        // print tree in-order
        void print();

    private:
        int arraySize;
        int noOfElementInHeap;
        int *array; // this is the heap
};
