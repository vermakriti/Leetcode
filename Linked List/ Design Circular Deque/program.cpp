/*

Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise.
 

Example 1:

Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]

Explanation
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4

*/


class DListNode{
    public:
    int val;
    DListNode*prev,*next;
    DListNode(){
        prev=nullptr;
        next=nullptr;
        val=0;
    }
    DListNode(int x){
        prev=nullptr;
        next=nullptr;
        val=x;
    }
};
class MyCircularDeque {
public:
    int size,count;
    DListNode*front,*last;
    
    MyCircularDeque(int k) {
        size=k;
        count=0;
        front=nullptr;
        last=nullptr;
    }
    bool insertFront(int value) {
        if(count==size)
            return false;
        DListNode*node = new DListNode(value);
        count++;
        if(front==nullptr){
            front=node;
            last=node;
        }
        else{
            node->next=front;
            front->prev=node;
            front=node;
        }
        last->next=front;
        return true;
    }
    bool insertLast(int value) {
        if(count==size)
            return false;
        DListNode*node = new DListNode(value);
        count++;
        if(front==nullptr){
            front=node;
            last=node;
        }
        else{
            last->next=node;
            node->prev=last;
            last=node;
        }
        last->next=front;
        return true;
    }
    bool deleteFront() {
        if(count==0)
            return false;
        if(count==1){
            front=nullptr;
            last=nullptr;
            count=0;
        }
        else{
            front=front->next;
            last->next=front;
            count--;
        }
        return true;
    }
    
    bool deleteLast() {
        if(count==0)
            return false;
        if(count==1){
            front=nullptr;
            last=nullptr;
            count=0;
        }
        else{
            last=last->prev;
            last->next=front;
            count--;
        }
        return true;
    }
    
    int getFront() {
        if(count==0)
            return -1;
        return front->val;
    }
    
    int getRear() {
        if(count==0)
            return -1;
        return last->val;
    }
    
    bool isEmpty() {
        if(count==0)
            return true;
        return false;
    }
    
    bool isFull() {
        if(count==size)
            return true;
        return false;
    }
};
