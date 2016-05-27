#include <iostream>
#include "adt_queue.h"
 
using namespace std;

Queue::Queue(int size){
    queue     = new int(size);
    queueSize = size;
    for(int i=0; i<size; ++i) {
        queue[i]=0;
    }
    head=0;
    tail=0;
}


bool 
Queue::enqueue(int val) {
    if(head == (tail+1) % queueSize) {
        cout << "queue full" << endl;
        return 0;
    } else {
        queue[tail] = val;
        tail = (tail + 1) % queueSize;
        return 1;
    }
}


int 
Queue::dequeue() {
    if(head==tail) {
        return -1;
    } else {
        int temp = queue[head];
        queue[head]=0;
        head = (head + 1) % queueSize;
        return temp;
    }
}

void
Queue::print() {
    cout << "-----------------" <<endl;
    cout << "head/tail " << head << "/" << tail  <<endl;
    for(int i=head; i != tail; i=(i+1)%queueSize){
        cout << "index = " << i << " value = " << queue[i] << endl;
    }
    cout << "-----------------" <<endl;
}


bool
Queue::empty() {
    if(head==tail) {
        cout << "queue is empty" << endl;
        return 1; // 1 means empty
    } else {
        cout << "Queue is non-empty" << endl;
        return 0; // 0 means non-empty
    }
}

int
Queue::size() {
    if(head <= tail) {
        cout << "queue conatins " << tail-head << " items" << endl;
        return tail-head;
    } else {
        cout << "queue conatins " << head+tail-1 << " items" << endl;
       return head+tail-1; 
    }
}


int main() 
{
    Queue q(10);

    q.empty();
    q.size();
    for(int i=0;i<12;++i) {
        q.enqueue(i);
    }

    q.size();
    q.print();
    for(int i=0;i<6;++i) {
        q.dequeue();
    }

    q.size();
    q.print();
    for(int i=0;i<8;++i) {
        q.enqueue(i);
    }

    q.size();
    q.print();
    for(int i=0;i<6;++i) {
        q.dequeue();
    }
}


/*
(05.19.2016 20:04:13) [tarunsharma@TARUSHA2-M-70VB ~/desktop/personal/code/adt] $  ./a.out
queue is empty
queue conatins 0 items
queue full
queue full
queue full
queue conatins 9 items
-----------------
head/tail 0/9
index = 0 value = 0
index = 1 value = 1
index = 2 value = 2
index = 3 value = 3
index = 4 value = 4
index = 5 value = 5
index = 6 value = 6
index = 7 value = 7
index = 8 value = 8
-----------------
queue conatins 3 items
-----------------
head/tail 6/9
index = 6 value = 6
index = 7 value = 7
index = 8 value = 8
-----------------
queue full
queue full
queue conatins 10 items
-----------------
head/tail 6/5
index = 6 value = 6
index = 7 value = 7
index = 8 value = 8
index = 9 value = 0
index = 0 value = 1
index = 1 value = 2
index = 2 value = 3
index = 3 value = 4
index = 4 value = 5
-----------------
*/
