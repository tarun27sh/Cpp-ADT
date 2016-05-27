/*  
 * for +ve nos only
 *
 * TODO:
 * 1. In the last run, I see 2 '9's in the heap, we only insert one, fix it
 *
 */

#include <iostream>
#include <queue>
#include <cassert>
#include "adt_heap.h"

using namespace std;

Heap::Heap(){
}

Heap::Heap(int size){
    arraySize = size;
    noOfElementInHeap = 0;
    array = new int[size];
}

// insert the element to the end of the array
// and then heapify()
bool 
Heap::insert(int value) {
    cout << "insert(" << value << ")" << endl;
    if(noOfElementInHeap == arraySize) {
        cout << "\theap full" << endl;
    } else {
        array[noOfElementInHeap] = value;
        ++noOfElementInHeap;
    }
    heapify_after_insert();
    cout << endl;
    return 1;
}

// extractMin the element at 'position'
// delete the tail element and copy its value to 'position'
// and then heapify()
bool
Heap::extractMin(void) {
    int position = 0;
    cout << "extractMin(" << array[position] << "):" << endl;
    if(noOfElementInHeap == 0) {
        cout << "\theap is empty" << endl;
        return 0;
    } else {
        array[position] = array[noOfElementInHeap - 1];
        array[noOfElementInHeap-1] = 0;
        --noOfElementInHeap;
        heapify_after_remove();
    }
    return 1;
}

// this is a min-heap, so children should be >=  parent
// find 
void
Heap::heapify_after_remove(void) {
    cout << "heapify_after_remove():" << endl;
    int position = 0;
    int compare_index = 0;
    while(2*position+1 < noOfElementInHeap) {
        cout << "\tposition=" << position << endl;
        cout << endl;

        // find smaller of 2 children
        if( 2*position+2 >= noOfElementInHeap) {
            // only one child
            compare_index = 2*position +1;
        } else {
            // two cjildren
            if(array[2*position + 1] < array[2*position + 2]) {
                compare_index = 2*position +1;
            } else {
                compare_index = 2*position +2;
            }
        }

        // check if new root is greater than the smaller child
        // if yes, swap
        if(array[position] > array[compare_index]) {
            cout << "\tswapping [" << position << "]=" << array[position] << " with [" << compare_index << "]=" << array[compare_index] << endl;
            int temp = array[position];
            array[position] = array[compare_index];
            array[compare_index] = temp;
            position = compare_index;
        } else {
            cout << "\tDone" << endl << endl;
            break;
        }
    }
    cout << "\tDone" << endl << endl;
}

void
Heap::heapify_after_insert(void) {
    // since this is the last element
    int position = noOfElementInHeap-1;
    while(position) {
        // parent at (position-1)/2
        if(array[position] < array[(position-1)/ 2]) {
            // swap
            int temp = array[position];
            array[position] = array[(position-1)/2];
            array[(position-1)/2] = temp;
        } else {
            cout << "\t heapify_after_insert() done" << endl;
            break;
        }
        position = (position-1)/2;
    }
}



int
Heap::minimum() {
    assert(noOfElementInHeap > 0);
    return array[0];
}

void
Heap::print() {
    cout << "print():\n";
    cout << "\tsize=" << noOfElementInHeap <<  endl;
    if(noOfElementInHeap == 0) {
        cout << "\tEmpty heap!!" << endl;
    } else {
        cout << "\tformat <left child, root, right child>" << endl;
        cout << "\t'-1' = NULL" << endl;
        int k=1;
        int j=0;
        for(int i=0; i < noOfElementInHeap; ++i) {
            //if(i is a power of 2, or i=2^x - 1,2,4,8)
            //    enter newline
            if(j == k) {
                cout << endl;
                k*=2;
                j=0;
            }
            ++j;
            int left, right;
            2*i+1 < noOfElementInHeap ? left = array[2*i+1] : left = -1;
            2*i+2 < noOfElementInHeap ? right = array[2*i+2] : right = -1;
            cout << "\t" << left << "," << array[i] << "," << right << "\t";
        }
    }
    cout << "\n" << endl;
}

bool
Heap::empty() {
    if(noOfElementInHeap == 0) {
        return 1;
    } else {
        return 0;
    }
}

int
Heap::size() {
    cout << "size():" << noOfElementInHeap << endl;
    return noOfElementInHeap;
}


int main() 
{
    Heap h(20);
    h.size();
    h.print();

    h.insert(21);
    h.print();
    h.insert(9);
    h.print();
    h.insert(31);
    h.print();
    h.insert(4);
    h.print();
    h.insert(16);
    h.print();
    h.insert(24);
    h.print();
    h.insert(36);
    h.print();
    h.insert(5);
    h.print();
    h.insert(1);
    h.print();
    h.size();
    h.extractMin();
    h.print();
    h.extractMin();
    h.print();
    h.extractMin();
    h.print();
    h.extractMin();
    h.print();
    h.extractMin();
    h.print();
    h.extractMin();
    h.print();
    h.extractMin();
    h.print();
    h.extractMin();
    h.print();
    h.extractMin();
    h.print();
    h.extractMin();
    h.print();
    return 0;
}

/*
======
OUTPUT:
======

g++ -g adt_heap.cpp

./a.out

size():0
print():
	size=0
	Empty heap!!


insert(21)

print():
	size=1
	format <left child, root, right child>
	'-1' = NULL
	-1,21,-1	

insert(9)

print():
	size=2
	format <left child, root, right child>
	'-1' = NULL
	21,9,-1	
	-1,21,-1	

insert(31)
	 heapify_after_insert() done

print():
	size=3
	format <left child, root, right child>
	'-1' = NULL
	21,9,31	
	-1,21,-1		-1,31,-1	

insert(4)

print():
	size=4
	format <left child, root, right child>
	'-1' = NULL
	9,4,31	
	21,9,-1		-1,31,-1	
	-1,21,-1	

insert(16)
	 heapify_after_insert() done

print():
	size=5
	format <left child, root, right child>
	'-1' = NULL
	9,4,31	
	21,9,16		-1,31,-1	
	-1,21,-1		-1,16,-1	

insert(24)
	 heapify_after_insert() done

print():
	size=6
	format <left child, root, right child>
	'-1' = NULL
	9,4,24	
	21,9,16		31,24,-1	
	-1,21,-1		-1,16,-1		-1,31,-1	

insert(36)
	 heapify_after_insert() done

print():
	size=7
	format <left child, root, right child>
	'-1' = NULL
	9,4,24	
	21,9,16		31,24,36	
	-1,21,-1		-1,16,-1		-1,31,-1		-1,36,-1	

insert(5)
	 heapify_after_insert() done

print():
	size=8
	format <left child, root, right child>
	'-1' = NULL
	5,4,24	
	9,5,16		31,24,36	
	21,9,-1		-1,16,-1		-1,31,-1		-1,36,-1	
	-1,21,-1	

insert(1)

print():
	size=9
	format <left child, root, right child>
	'-1' = NULL
	4,1,24	
	5,4,16		31,24,36	
	21,5,9		-1,16,-1		-1,31,-1		-1,36,-1	
	-1,21,-1		-1,9,-1	

size():9
extractMin(1):
heapify_after_remove():
	position=0

	swapping [0]=9 with [1]=4
	position=1

	swapping [1]=9 with [3]=5
	position=3

	Done

	Done

print():
	size=8
	format <left child, root, right child>
	'-1' = NULL
	5,4,24	
	9,5,16		31,24,36	
	21,9,-1		-1,16,-1		-1,31,-1		-1,36,-1	
	-1,21,-1	

extractMin(4):
heapify_after_remove():
	position=0

	swapping [0]=21 with [1]=5
	position=1

	swapping [1]=21 with [3]=9
	Done

print():
	size=7
	format <left child, root, right child>
	'-1' = NULL
	9,5,24	
	21,9,16		31,24,36	
	-1,21,-1		-1,16,-1		-1,31,-1		-1,36,-1	

extractMin(5):
heapify_after_remove():
	position=0

	swapping [0]=36 with [1]=9
	position=1

	swapping [1]=36 with [4]=16
	Done

print():
	size=6
	format <left child, root, right child>
	'-1' = NULL
	16,9,24	
	21,16,36		31,24,-1	
	-1,21,-1		-1,36,-1		-1,31,-1	

extractMin(9):
heapify_after_remove():
	position=0

	swapping [0]=31 with [1]=16
	position=1

	swapping [1]=31 with [3]=21
	Done

print():
	size=5
	format <left child, root, right child>
	'-1' = NULL
	21,16,24	
	31,21,36		-1,24,-1	
	-1,31,-1		-1,36,-1	

extractMin(16):
heapify_after_remove():
	position=0

	swapping [0]=36 with [1]=21
	position=1

	swapping [1]=36 with [3]=31
	Done

print():
	size=4
	format <left child, root, right child>
	'-1' = NULL
	31,21,24	
	36,31,-1		-1,24,-1	
	-1,36,-1	

extractMin(21):
heapify_after_remove():
	position=0

	swapping [0]=36 with [2]=24
	Done

print():
	size=3
	format <left child, root, right child>
	'-1' = NULL
	31,24,36	
	-1,31,-1		-1,36,-1	

extractMin(24):
heapify_after_remove():
	position=0

	swapping [0]=36 with [1]=31
	Done

print():
	size=2
	format <left child, root, right child>
	'-1' = NULL
	36,31,-1	
	-1,36,-1	

extractMin(31):
heapify_after_remove():
	Done

print():
	size=1
	format <left child, root, right child>
	'-1' = NULL
	-1,36,-1	

extractMin(36):
heapify_after_remove():
	Done

print():
	size=0
	Empty heap!!


extractMin(0):
	heap is empty
print():
	size=0
	Empty heap!!
*/

