/*  
 *  Each index of this HT implementation is a Singly-linked linked list
 *  Insertion: O(1) worst case - inserts nodes to the begining of the linkedlist.
 *  Removal:   O(N) worst case - this implementation uses a single-linkedlist, it 
 *              requires traversing the linkedlist to discover the predecessor and 
 *              then point it to current->next and then delete current. This can be 
 *              made O(1) by using doubly linked list.
 *  Lookup:    O(N) worst case
 */


#include <iostream>
#include "adt_ht.h"

using namespace std;

HashTable::HashTable(int size){
    ht = new bucket[size];
    for(int i=0; i<size; ++i) {
        ht[i].head = NULL;
        ht[i].size = 0;
    }
    noOfItems    = 0;
    noOfBuckets = size;
}

// O(1)
// insert to the head
// argument is a item 'x' containing x.key & x.value
bool 
HashTable::insert(int key, int value) {
    cout << "insert(): key=" << key << " val=" << value << " hash(key)=" << hash(key) << endl;

    node* temp_node = new node;
    temp_node->val = value;
    temp_node->key = key;
    temp_node->next = NULL;

    bucket temp_bucket = ht[hash(key)];
    if(temp_bucket.head == NULL) {
        cout << "\tbucket doesn't exist, creating one" << endl;
        ht[hash(key)].head = temp_node;
        ht[hash(key)].size = 1;
    } else {
        cout << "\tadding to existing bucket" << endl;
        ++ht[hash(key)].size;
        node* temp_node2 = temp_bucket.head;
        while(temp_node2->next) {
            temp_node2 = temp_node2->next;
        }
        temp_node2->next = temp_node;
    }
    ++noOfItems;
    return 1;
}

// worst case O(n)
int 
HashTable::remove(int key, int val) {
    cout << "remove(): key/val="<<key<<"/"<<val << endl;
    // 1. element is head                       - modify head
    // 2. element is in the middle somewhere    - no change
    // 3. element is last element               - no change
    bucket *temp_bucket= &ht[hash(key)];

    if(temp_bucket->head == NULL) {
        cout << "\tERROR!! bucket empty" << endl;
        return -1;
    } else {
        node *head = temp_bucket->head;
        node *temp = head;
        node *prev = NULL;
        cout << "\tbucket#" << key%noOfBuckets << "(size="<<temp_bucket->size << ")" << endl;
        if(temp->val == val) {
            cout << "\tElement to be removed is at the head" << endl;
            temp_bucket->head = temp_bucket->head->next;
            --temp_bucket->size;
            --noOfItems;
            delete temp;
            return 1;
        } else {
            prev = temp;
            temp = temp->next; // this can be NULL

            while(temp) {
                if(temp->val == val) {
                    cout << "\tFound the item at a non-head position" << endl;
                    prev->next = temp->next;
                    --temp_bucket->size;
                    --noOfItems;
                    delete temp;
                    return 1;
                }
                prev = temp;
                temp = temp->next;
            }
            cout << "\tItem not found" << endl;
        }
        return -1;
    }
}

int
HashTable::hash(int key) {
   return  key%noOfBuckets;
}

void
HashTable::print() {
    cout << "-----------------" <<endl;
    cout << "print():" << endl;
    cout << "Total count  = " << noOfItems <<endl;
    cout << "# of buckets = " << noOfBuckets <<endl;
    for (int i=0; i<noOfBuckets; ++i) {
        cout << "Bucket#" << i << " (" << ht[i].size << ")" << endl;
        node* temp = ht[i].head;
        int j=0; // indexing
        while(temp != NULL) {
            cout << "\t[" << j << "] key = " << temp->key << "  value = " << temp->val << endl;
            temp = temp->next;
            ++j;
        }
    }
    cout << "-----------------" <<endl;
}

int
lookup(int key) {
    return 0;
}

bool
HashTable::empty() {
    cout << "empty():" << endl;
    if(noOfItems == 0) {
        cout << "ht is empty" << endl;
        return 1; // 1 means empty
    } else {
        cout << "HashTable is non-empty" << endl;
        return 0; // 0 means non-empty
    }
}

int
HashTable::size() {
    cout << "size():" << endl;
    cout << "size=" << noOfItems << endl;
    return noOfItems;
}


int main() 
{
    // Keeping HT size (aka # of buckets) as prime helps keeping collisions low
    HashTable ht(13);
    ht.empty();
    ht.size();
    for(int i=1000;i<1042;++i) {
        ht.insert(i, i); // key is same as value
    }
    ht.size();
    ht.print();
    ht.remove(1000, 1000); // a head element
    for(int i=1020;i<1030;++i) {
        ht.remove(i, i); // key is same as value
    }
    ht.size();
    ht.print();

    ht.remove(10, 10); 
    ht.remove(10343, 1034534); 
    ht.remove(150, 10); 
    ht.remove(0, 1330); 
    ht.remove(100000000, 10); 
    return 0;
}

/*
g++ -g adt_ht.cpp

Output:

    empty():
    ht is empty
    size():
    size=0
    insert(): key=1000 val=1000 hash(key)=12
    	bucket doesn't exist, creating one
    insert(): key=1001 val=1001 hash(key)=0
    	bucket doesn't exist, creating one
    insert(): key=1002 val=1002 hash(key)=1
    	bucket doesn't exist, creating one
    insert(): key=1003 val=1003 hash(key)=2
    	bucket doesn't exist, creating one
    insert(): key=1004 val=1004 hash(key)=3
    	bucket doesn't exist, creating one
    insert(): key=1005 val=1005 hash(key)=4
    	bucket doesn't exist, creating one
    insert(): key=1006 val=1006 hash(key)=5
    	bucket doesn't exist, creating one
    insert(): key=1007 val=1007 hash(key)=6
    	bucket doesn't exist, creating one
    insert(): key=1008 val=1008 hash(key)=7
    	bucket doesn't exist, creating one
    insert(): key=1009 val=1009 hash(key)=8
    	bucket doesn't exist, creating one
    insert(): key=1010 val=1010 hash(key)=9
    	bucket doesn't exist, creating one
    insert(): key=1011 val=1011 hash(key)=10
    	bucket doesn't exist, creating one
    insert(): key=1012 val=1012 hash(key)=11
    	bucket doesn't exist, creating one
    insert(): key=1013 val=1013 hash(key)=12
    	adding to existing bucket
    insert(): key=1014 val=1014 hash(key)=0
    	adding to existing bucket
    insert(): key=1015 val=1015 hash(key)=1
    	adding to existing bucket
    insert(): key=1016 val=1016 hash(key)=2
    	adding to existing bucket
    insert(): key=1017 val=1017 hash(key)=3
    	adding to existing bucket
    insert(): key=1018 val=1018 hash(key)=4
    	adding to existing bucket
    insert(): key=1019 val=1019 hash(key)=5
    	adding to existing bucket
    insert(): key=1020 val=1020 hash(key)=6
    	adding to existing bucket
    insert(): key=1021 val=1021 hash(key)=7
    	adding to existing bucket
    insert(): key=1022 val=1022 hash(key)=8
    	adding to existing bucket
    insert(): key=1023 val=1023 hash(key)=9
    	adding to existing bucket
    insert(): key=1024 val=1024 hash(key)=10
    	adding to existing bucket
    insert(): key=1025 val=1025 hash(key)=11
    	adding to existing bucket
    insert(): key=1026 val=1026 hash(key)=12
    	adding to existing bucket
    insert(): key=1027 val=1027 hash(key)=0
    	adding to existing bucket
    insert(): key=1028 val=1028 hash(key)=1
    	adding to existing bucket
    insert(): key=1029 val=1029 hash(key)=2
    	adding to existing bucket
    insert(): key=1030 val=1030 hash(key)=3
    	adding to existing bucket
    insert(): key=1031 val=1031 hash(key)=4
    	adding to existing bucket
    insert(): key=1032 val=1032 hash(key)=5
    	adding to existing bucket
    insert(): key=1033 val=1033 hash(key)=6
    	adding to existing bucket
    insert(): key=1034 val=1034 hash(key)=7
    	adding to existing bucket
    insert(): key=1035 val=1035 hash(key)=8
    	adding to existing bucket
    insert(): key=1036 val=1036 hash(key)=9
    	adding to existing bucket
    insert(): key=1037 val=1037 hash(key)=10
    	adding to existing bucket
    insert(): key=1038 val=1038 hash(key)=11
    	adding to existing bucket
    insert(): key=1039 val=1039 hash(key)=12
    	adding to existing bucket
    insert(): key=1040 val=1040 hash(key)=0
    	adding to existing bucket
    insert(): key=1041 val=1041 hash(key)=1
    	adding to existing bucket
    size():
    size=42
    -----------------
    print():
    Total count  = 42
    # of buckets = 13
    Bucket#0 (4)
    	[0] key = 1001  value = 1001
    	[1] key = 1014  value = 1014
    	[2] key = 1027  value = 1027
    	[3] key = 1040  value = 1040
    Bucket#1 (4)
    	[0] key = 1002  value = 1002
    	[1] key = 1015  value = 1015
    	[2] key = 1028  value = 1028
    	[3] key = 1041  value = 1041
    Bucket#2 (3)
    	[0] key = 1003  value = 1003
    	[1] key = 1016  value = 1016
    	[2] key = 1029  value = 1029
    Bucket#3 (3)
    	[0] key = 1004  value = 1004
    	[1] key = 1017  value = 1017
    	[2] key = 1030  value = 1030
    Bucket#4 (3)
    	[0] key = 1005  value = 1005
    	[1] key = 1018  value = 1018
    	[2] key = 1031  value = 1031
    Bucket#5 (3)
    	[0] key = 1006  value = 1006
    	[1] key = 1019  value = 1019
    	[2] key = 1032  value = 1032
    Bucket#6 (3)
    	[0] key = 1007  value = 1007
    	[1] key = 1020  value = 1020
    	[2] key = 1033  value = 1033
    Bucket#7 (3)
    	[0] key = 1008  value = 1008
    	[1] key = 1021  value = 1021
    	[2] key = 1034  value = 1034
    Bucket#8 (3)
    	[0] key = 1009  value = 1009
    	[1] key = 1022  value = 1022
    	[2] key = 1035  value = 1035
    Bucket#9 (3)
    	[0] key = 1010  value = 1010
    	[1] key = 1023  value = 1023
    	[2] key = 1036  value = 1036
    Bucket#10 (3)
    	[0] key = 1011  value = 1011
    	[1] key = 1024  value = 1024
    	[2] key = 1037  value = 1037
    Bucket#11 (3)
    	[0] key = 1012  value = 1012
    	[1] key = 1025  value = 1025
    	[2] key = 1038  value = 1038
    Bucket#12 (4)
    	[0] key = 1000  value = 1000
    	[1] key = 1013  value = 1013
    	[2] key = 1026  value = 1026
    	[3] key = 1039  value = 1039
    -----------------
    remove(): key/val=1000/1000
    	bucket#12(size=4)
    	Element to be removed is at the head
    remove(): key/val=1020/1020
    	bucket#6(size=3)
    	Found the item at a non-head position
    remove(): key/val=1021/1021
    	bucket#7(size=3)
    	Found the item at a non-head position
    remove(): key/val=1022/1022
    	bucket#8(size=3)
    	Found the item at a non-head position
    remove(): key/val=1023/1023
    	bucket#9(size=3)
    	Found the item at a non-head position
    remove(): key/val=1024/1024
    	bucket#10(size=3)
    	Found the item at a non-head position
    remove(): key/val=1025/1025
    	bucket#11(size=3)
    	Found the item at a non-head position
    remove(): key/val=1026/1026
    	bucket#12(size=3)
    	Found the item at a non-head position
    remove(): key/val=1027/1027
    	bucket#0(size=4)
    	Found the item at a non-head position
    remove(): key/val=1028/1028
    	bucket#1(size=4)
    	Found the item at a non-head position
    remove(): key/val=1029/1029
    	bucket#2(size=3)
    	Found the item at a non-head position
    size():
    size=31
    -----------------
    print():
    Total count  = 31
    # of buckets = 13
    Bucket#0 (3)
    	[0] key = 1001  value = 1001
    	[1] key = 1014  value = 1014
    	[2] key = 1040  value = 1040
    Bucket#1 (3)
    	[0] key = 1002  value = 1002
    	[1] key = 1015  value = 1015
    	[2] key = 1041  value = 1041
    Bucket#2 (2)
    	[0] key = 1003  value = 1003
    	[1] key = 1016  value = 1016
    Bucket#3 (3)
    	[0] key = 1004  value = 1004
    	[1] key = 1017  value = 1017
    	[2] key = 1030  value = 1030
    Bucket#4 (3)
    	[0] key = 1005  value = 1005
    	[1] key = 1018  value = 1018
    	[2] key = 1031  value = 1031
    Bucket#5 (3)
    	[0] key = 1006  value = 1006
    	[1] key = 1019  value = 1019
    	[2] key = 1032  value = 1032
    Bucket#6 (2)
    	[0] key = 1007  value = 1007
    	[1] key = 1033  value = 1033
    Bucket#7 (2)
    	[0] key = 1008  value = 1008
    	[1] key = 1034  value = 1034
    Bucket#8 (2)
    	[0] key = 1009  value = 1009
    	[1] key = 1035  value = 1035
    Bucket#9 (2)
    	[0] key = 1010  value = 1010
    	[1] key = 1036  value = 1036
    Bucket#10 (2)
    	[0] key = 1011  value = 1011
    	[1] key = 1037  value = 1037
    Bucket#11 (2)
    	[0] key = 1012  value = 1012
    	[1] key = 1038  value = 1038
    Bucket#12 (2)
    	[0] key = 1013  value = 1013
    	[1] key = 1039  value = 1039
    -----------------
    remove(): key/val=10/10
    	bucket#10(size=2)
    	Item not found
    remove(): key/val=10343/1034534
    	bucket#8(size=2)
    	Item not found
    remove(): key/val=150/10
    	bucket#7(size=2)
    	Item not found
    remove(): key/val=0/1330
    	bucket#0(size=3)
    	Item not found
    remove(): key/val=100000000/10
	    bucket#9(size=2)
	    Item not found
*/	    
