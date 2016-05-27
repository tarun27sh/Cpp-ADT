/*
 *  Singly-linked linked list
 *  inserts nodes to the begining of the ll.
 */


#include <iostream>
#include "adt_ll.h"

using namespace std;

LinkedList::LinkedList(){
    head         = NULL;
    noOfItems    = 0;
}

// O(1)
bool 
LinkedList::insert(int val) {
    cout << "insert():" << endl;
    node* temp = new node;
    temp->val  = val;
    temp->next = NULL;
    if(head == NULL) {
        head = temp;
    } else {
        temp->next = head;
        head = temp;
    }
    ++noOfItems;
    cout << "Item "<< val << " inserted  Total " << noOfItems << endl;
    return 1;
}

// worst case O(n)
int 
LinkedList::remove(int val) {
    // 1. element is head                       - modify head
    // 2. element is in the middle somewhere    - no change
    // 3. element is last element               - no change
    cout << "remove():" << endl;
    node* temp = head;
    node* prev = NULL;
    while(temp && temp->val != val) {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        cout << "NOT FOUND!!" << endl;
        return -1;
    } else {
        if(temp == head) { // 1
            head = head->next;
        } else { // 2 & 3
            prev->next = temp->next;
        }
        delete temp;
        --noOfItems;
        cout << "Item "<< val << " removed  Total " << noOfItems << endl;

        return 0;
    }
}

void
LinkedList::print() {
    cout << "-----------------" <<endl;
    cout << "print():" << endl;
    cout << "Total count = " << noOfItems <<endl;
    node *temp=head;
    int i=0;
    while(temp != NULL) {
        cout << "    [" << i << "] val=" << temp->val <<endl;
        temp=temp->next;
        ++i;
    }
    cout << "-----------------" <<endl;
}


bool
LinkedList::empty() {
    cout << "empty():" << endl;
    if(noOfItems == 0) {
        cout << "ll is empty" << endl;
        return 1; // 1 means empty
    } else {
        cout << "LinkedList is non-empty" << endl;
        return 0; // 0 means non-empty
    }
}

int
LinkedList::size() {
    cout << "size():" << endl;
    cout << "size=" << noOfItems << endl;
    return noOfItems;
}


int main() 
{
    LinkedList ll;

    ll.empty();
    ll.size();
    for(int i=0;i<12;++i) {
        ll.insert(i);
    }

    ll.size();
    ll.print();
    for(int i=0;i<6;++i) {
        ll.remove(i);
    }

    ll.size();
    ll.print();
    for(int i=12;i<20;++i) {
        ll.insert(i);
    }

    ll.size();
    ll.print();
    for(int i=14;i<19;++i) {
        ll.remove(i);
    }
    ll.print();
}

/*

g++ -g adt_ll.cpp -o ll
./ll

empty():
ll is empty
size():
size=0
insert():
Item 0 inserted  Total 1
insert():
Item 1 inserted  Total 2
insert():
Item 2 inserted  Total 3
insert():
Item 3 inserted  Total 4
insert():
Item 4 inserted  Total 5
insert():
Item 5 inserted  Total 6
insert():
Item 6 inserted  Total 7
insert():
Item 7 inserted  Total 8
insert():
Item 8 inserted  Total 9
insert():
Item 9 inserted  Total 10
insert():
Item 10 inserted  Total 11
insert():
Item 11 inserted  Total 12
size():
size=12
-----------------
print():
Total count = 12
    [0] val=11
    [1] val=10
    [2] val=9
    [3] val=8
    [4] val=7
    [5] val=6
    [6] val=5
    [7] val=4
    [8] val=3
    [9] val=2
    [10] val=1
    [11] val=0
-----------------
remove():
Item 0 removed  Total 11
remove():
Item 1 removed  Total 10
remove():
Item 2 removed  Total 9
remove():
Item 3 removed  Total 8
remove():
Item 4 removed  Total 7
remove():
Item 5 removed  Total 6
size():
size=6
-----------------
print():
Total count = 6
    [0] val=11
    [1] val=10
    [2] val=9
    [3] val=8
    [4] val=7
    [5] val=6
-----------------
insert():
Item 12 inserted  Total 7
insert():
Item 13 inserted  Total 8
insert():
Item 14 inserted  Total 9
insert():
Item 15 inserted  Total 10
insert():
Item 16 inserted  Total 11
insert():
Item 17 inserted  Total 12
insert():
Item 18 inserted  Total 13
insert():
Item 19 inserted  Total 14
size():
size=14
-----------------
print():
Total count = 14
    [0] val=19
    [1] val=18
    [2] val=17
    [3] val=16
    [4] val=15
    [5] val=14
    [6] val=13
    [7] val=12
    [8] val=11
    [9] val=10
    [10] val=9
    [11] val=8
    [12] val=7
    [13] val=6
-----------------
remove():
Item 14 removed  Total 13
remove():
Item 15 removed  Total 12
remove():
Item 16 removed  Total 11
remove():
Item 17 removed  Total 10
remove():
Item 18 removed  Total 9
-----------------
print():
Total count = 9
    [0] val=19
    [1] val=13
    [2] val=12
    [3] val=11
    [4] val=10
    [5] val=9
    [6] val=8
    [7] val=7
    [8] val=6
-----------------
*/
