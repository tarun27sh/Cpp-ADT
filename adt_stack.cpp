#include <iostream>
#include <cassert>
#include "adt_stack.h"
 
using namespace std;

Stack::Stack(int size){
    stack     = new int(size);
    stackSize = size;
    for(int i=0; i<size; ++i) {
        stack[i]=0;
    }
    noOfItems = 0;
}


bool 
Stack::push(int val) {

    assert(noOfItems <= stackSize);

    if(noOfItems == stackSize) {
        cout << "stack full" << endl;
        return 0;
    } else {
        stack[noOfItems]=val;
        ++noOfItems;
        return 1;
    }
}


int 
Stack::pop() {
    assert(noOfItems > 0);

    --noOfItems;
    int temp=stack[noOfItems];
    cout << "Stack returned " << temp << " index = " << noOfItems << endl;
    stack[noOfItems]=0;
    return temp; 
}

void
Stack::print() {
    for(int i=noOfItems-1; i >= 0; --i){
        cout << "index = " << i << " value = " << stack[i] << endl;
    }
}


bool
Stack::empty() {
    if(noOfItems==0) {
        cout << "stack is empty" << endl;
        return 1; // 1 means empty
    } else {
        cout << "Stack is non-empty" << endl;
        return 0; // 0 means non-empty
    }
}

int
Stack::size() {
    cout << "stack conatins " << noOfItems << " items" << endl;
    return noOfItems;
}


int
Stack::top() {
    cout << "top item = " << stack[noOfItems-1] << " index=" << noOfItems-1 <<endl;
    return stack[noOfItems-1];
}

int main() 
{
    Stack s(10);
    s.empty();
    s.size();
    for(int i=0;i<5;++i) {
        s.push(i);
    }
    s.size();
    cout << "-----------------" <<endl;
    s.print();
    cout << "-----------------" <<endl;
    s.pop();
    s.size();
    s.top();
    cout << "-----------------" <<endl;
    s.print();
}
