/*
*/


#include <iostream>
 
using namespace std;

typedef struct node {
    int   val;
    node* left;
    node* right;
    node* parent;
}node;

class BinarySearchTree {
    public:
        // default constructor
        BinarySearchTree();

        // parameterized constructor
        BinarySearchTree(int);

        // Returns whether the queue is empty
        bool empty();

        // Returns the number of elements in the queue.
        int size();

        // Returns a reference to the min element
        node *minimum(node*);

        // Returns a reference to the max element
        int maximum(node *);

        // Inserts a new element in the tree
        bool insert(int);

        // Removes the element from the tree and RET
        int remove(int);

        // return the location of the node, and RET
        node* lookup(int);

        // return the location of the node, and RET
        node* lookup(int, node**);

        // successor
        int successor(node*);

        // predecessor
        int predecessor(node*);

        // print tree in-order
        void print();

    private:
        int noOfItems;
        node* root;
};
