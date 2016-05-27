/*  
 */


#include <iostream>
#include <queue>
#include <cassert>
#include "adt_bst.h"

using namespace std;

BinarySearchTree::BinarySearchTree(){
    noOfItems = 0;
    root      = NULL;
}

// O(1)
// insert to the head
// argument is a item 'x' containing x.key & x.value
bool 
BinarySearchTree::insert(int value) {
    cout << "insert(" << value << ")" << endl;

    node* temp_node = new node;
    temp_node->val = value;
    temp_node->parent = NULL;
    temp_node->left = NULL;
    temp_node->right = NULL;
    if(root == NULL) {
        cout << "\tempty tree, adding as head" << endl;
        root = temp_node;
    } else {
        // this will go in as per its val,
        // if val > root, right subtree
        // if val < root, left subtree
        // go like this untill right/left subtree = NULL
        node* temp = root;
        node* prev = NULL;
        while(temp!=NULL) {
            prev = temp;
            if(value > temp->val) {
                temp = temp->right;
            } else {
                temp = temp->left;
            }
        }
        prev->val > value ? prev->left = temp_node : prev->right = temp_node;
    }
    ++noOfItems;
    cout << endl;
    return 1;
}

node* 
BinarySearchTree::lookup(int val) {
    assert(root!=NULL && "root is NULL");
    cout << "lookup(" << val << "):"<< endl;
    node* temp = root;
    while(temp) {
        if(temp->val == val) {
            int left, right;
            temp->left==NULL? left=-1: left=temp->left->val;
            temp->right==NULL? right=-1: right=temp->right->val;
            cout << "\tFound: " << left << "," << temp->val << "," << right << endl;
            cout << endl;
            return temp;
        }
        if(val > temp->val) {
            temp = temp->right;
        } else {
            temp = temp->left;
        }
    }
    cout << "\tNot found !" << endl;
    cout << endl;
    return NULL;

}
node* 
BinarySearchTree::lookup(int val, node** prev) {
    assert(root!=NULL && "root is NULL");
    *prev=NULL;
    cout << "lookup(" << val << "):"<< endl;
    node* temp = root;
    while(temp) {
        if(temp->val == val) {
            int left, right;
            temp->left==NULL? left=-1: left=temp->left->val;
            temp->right==NULL? right=-1: right=temp->right->val;
            cout << "\tFound: " << left << "," << temp->val << "," << right << endl;
            return temp;
        }
        *prev=temp;
        if(val > temp->val) {
            temp = temp->right;
        } else {
            temp = temp->left;
        }
    }
    cout << endl;
    return NULL;
}

// worst case O(n)
// this is a recursive function
// if the node to be deleted has 2 children, we find the minimum
// in the right subtree of this root, copy its value to root and 
// then delete minimun node - by recursively calling remove().
int 
BinarySearchTree::remove(int val) {
    cout << "remove(): val=" << val << endl;
    node* prev = NULL;
    node* temp = lookup(val, &prev);
    if(prev == NULL) {
        cout << "\tremoving the head element\n";
    }
    //Case 1: no children
    if (temp->right==NULL && temp->left == NULL) {
        prev->right == temp ? prev->right = NULL: prev->left = NULL;
        delete temp;
    //Case 2: 1 children ie right child exists
    } else if(temp->left == NULL) {
        prev->right == temp ? prev->right = temp->right: prev->left = temp->right;
        delete temp;
    //Case 2: 1 children ie left child exists
    } else if (temp->right == NULL) {
        prev->right == temp ? prev->right = temp->left: prev->left = temp->left;
        delete temp;
    //Case 3: 2 children
    } else {
        // if   root->right exists, find min element in right subtree
        node* min = minimum(temp->right);
        int val = min->val;
        remove(min->val);
        root->val = val;
    }
    cout << endl;
    return 1; //success
}

// this is a hlper function for remove
// it finds the minimum entry in the right subtree
// of the specified root - ie the node to be deleted
// successor = minimum(root->right)
node* 
BinarySearchTree::minimum(node* root) {
    int val = root->val;
    assert(root!=NULL);
    cout << "minimum(" << val << ")" << endl;
    node* min = NULL;
    while(root) {
        min = root;
        root = root->left;
    }
    cout << "\tmin(" << val << ") = " << min->val << endl <<  endl;
    return min;
}

// BFS
// TODO improve the format, make it look cool :)
// ugly code but gives meaningful output
void
BinarySearchTree::print() {
    queue<node*> q;// helper queue
    queue<node*> qp;
    cout << "----------------------" << endl;
    cout << "print():  format <left child, root, right child>" << endl;
    cout << "          * = NULL" << endl;
    if(root == NULL ) {
        cout << "\tCan't print something that is empty" << endl;
    } else {
        node* temp = root;
        q.push(temp);
        qp.push(temp);
        while(q.empty() == 0) {
            node* temp2 = q.front();
            if(temp2->left) {
                q.push(temp2->left);
                qp.push(temp2->left);
            }
            if(temp2->right) {
                q.push(temp2->right); 
                qp.push(temp2->right); 
            }
            q.pop();
        }
        cout << "size = " << qp.size()<< endl <<  endl;
        int k=0;
        int j=0;
        for(int i=1; i/2 < qp.size(); i*=2) {
            j=k;
            k=0;
            for(; j<i; ++j) {
                if(qp.empty()) {
                    i = qp.size();
                    j = i;
                    break;
                }
                // print row, j times
                int left, right;
                node* temp_root = qp.front();
                temp_root->left==NULL? left=-1,++k: left=temp_root->left->val;
                temp_root->right==NULL? right=-1, ++k: right=temp_root->right->val;
                if(left==-1 && right ==-1) {
                    cout << "*," << temp_root->val << ",*" << "\t ";
                } else if(left==-1) {
                    cout << "*," << temp_root->val << "," << right << "\t ";
                } else if(right==-1) {
                    cout << " " << left << "," << temp_root->val << ",*" << "\t ";
                } else {
                    cout << " " << left << "," << temp_root->val << "," << right << "\t ";
                }
                qp.pop();
            }
            cout << endl;
        }
        while(qp.empty() != 1) {
            int left, right;
            node* temp_root = qp.front();
            temp_root->left==NULL? left=-1,++k: left=temp_root->left->val;
            temp_root->right==NULL? right=-1, ++k: right=temp_root->right->val;
                if(left==-1 && right ==-1) {
                    cout << "*," << temp_root->val << ",*" << "\t ";
                } else if(left==-1) {
                    cout << "*," << temp_root->val << "," << right << "\t ";
                } else if(right==-1) {
                    cout << " " << left << "," << temp_root->val << ",*" << "\t ";
                } else {
                    cout << " " << left << "," << temp_root->val << "," << right << "\t ";
                }
           // cout << " " << left << "," << temp_root->val << "," << right << "\t ";
            qp.pop();
        }
        cout << endl;
        cout << "----------------------" << endl << endl;
    }
}

bool
BinarySearchTree::empty() {
    if(root == NULL && noOfItems == 0) {
    } else {
        assert(0 && "mismatch");
    }
    return 1;
}

int
BinarySearchTree::size() {
    cout << "size():" << noOfItems << endl;
    return noOfItems;
}


int main() 
{
    BinarySearchTree bst;
    bst.size();
    bst.print();

    bst.insert(21);
    bst.insert(9);
    bst.insert(31);
    bst.insert(4);
    bst.insert(16);
    bst.insert(24);
    bst.insert(36);

    bst.insert(20);
    bst.insert(10);
    bst.insert(30);
    bst.insert(5);
    bst.insert(15);
    bst.insert(25);
    bst.insert(35);
    bst.size();
    bst.print();
    bst.lookup(20);
    bst.lookup(25);
    bst.lookup(35);
    node* temp = bst.lookup(21);
    bst.lookup(9);
    bst.lookup(16);
    bst.lookup(36);
    bst.lookup(111);
    
    bst.minimum(temp->right);
    //bst.remove(25);
    //bst.remove(10);
    //bst.remove(36);
    bst.remove(21); // removing root
    bst.print();
    return 0;
}


/*
g++ -g adt_bst.cpp


=======
Output:
=======


size():0
----------------------
print():  format <left child, root, right child>
          * = NULL
	Can't print something that is empty
insert(21)
	empty tree, adding as head

insert(9)

insert(31)

insert(4)

insert(16)

insert(24)

insert(36)

insert(20)

insert(10)

insert(30)

insert(5)

insert(15)

insert(25)

insert(35)

size():14
----------------------
print():  format <left child, root, right child>
          * = NULL
size = 14

 9,21,31	 
 4,9,16	  24,31,36	 
*,4,5	  10,16,20	 *,24,30	  35,36,*	 
*,5,*	 *,10,15	 *,20,*	  25,30,*	 *,35,*	 
*,15,*	 *,25,*	 
----------------------

lookup(20):
	Found: -1,20,-1

lookup(25):
	Found: -1,25,-1

lookup(35):
	Found: -1,35,-1

lookup(21):
	Found: 9,21,31

lookup(9):
	Found: 4,9,16

lookup(16):
	Found: 10,16,20

lookup(36):
	Found: 35,36,-1

lookup(111):
	Not found !

minimum(31)
	min(31) = 24

remove(): val=21
lookup(21):
	Found: 9,21,31
	removing the head element
minimum(31)
	min(31) = 24

remove(): val=24
lookup(24):
	Found: -1,24,30


----------------------
print():  format <left child, root, right child>
          * = NULL
size = 13

 9,24,31	 
 4,9,16	  30,31,36	 
*,4,5	  10,16,20	  25,30,*	  35,36,*	 
*,5,*	 *,10,15	 *,20,*	 *,25,*	 *,35,*	 
*,15,*	 
----------------------
*/
