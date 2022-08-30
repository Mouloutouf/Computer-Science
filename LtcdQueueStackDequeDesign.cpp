// Queue Design with Linked List
// Uses Two Pointers, the Head which Represents the First Element of the Queue, and the Tail, which Represents the Last Element of the Queue
// When Adding an Element, we Add at the Tail, and if the Head is null (if the Queue is Empty) we Replace Head
// When Removing an Element, we Remove it from the Head, by Moving to the Next Node in the Queue, and if Head becomes null, the Queue has been Emptied, we put Tail at Null too
// then we return the Value of the Node we Removed

class Queue {
public:
    struct Node{
        int data;
        Node *next;

        Node()
        : data(-1), next(nullptr)
        {
        }

        Node(int _data, Node *_next)
        : data(_data), next(_next)
        {
        }
    };

    Node *head, *tail;

    Queue()
    : head(nullptr), tail(nullptr)
    {
    }
    
    void push(int x){
        Node *node = new Node(x, nullptr);
        if (tail != nullptr){
            tail->next = node;
        }
        tail = node;
        if (head == nullptr){
            head = node;
        }
    }
    
    int pop(){
        int data = 0;
        if (head != nullptr){
            data = head->data;
            head = head->next;
        }
        if (head == nullptr){
            tail = nullptr;
        }
        return data;
    }
    
    int peek(){
        if (head != nullptr){
            return head->data;
        }
        return 0; // Should return an exception
    }
    
    bool empty(){
        return head == nullptr;
    }
};

// Stack Design with Linked List
// Uses Only One Pointer Top to Access Elements from the Head of the List
// When Adding an Element we just replace Top with the New Element and make it point to the Former
// When Removing an Element we just make Top point to the Next Element, then Return the Value of the Node we Removed

class Stack {
public:
    struct Node{
        int data;
        Node *next;

        Node()
        : data(-1), next(nullptr)
        {
        }

        Node(int _data, Node *_next)
        : data(_data), next(_next)
        {
        }
    };

    Node *top;

    Stack()
    : top(nullptr)
    {
    }
    
    void push(int x){
        Node *cur = top;
        top = new Node(x, cur);
    }
    
    int pop(){
        if (top != nullptr){
            int data = top->data;
            top = top->next;
            return data;
        }
        return 0; // Should return an exception
    }
    
    int peek(){
        if (top != nullptr){
            return top->data;
        }
        return 0; // Should return an exception
    }
    
    bool empty(){
        return top == nullptr;
    }
};

// Deque or Double-Ended Queue Design using a Doubly-Linked List
// We can Add Elements either at the Front or Back, the Process is Symetrical. We create a New Node, make the Current Node Next or Prev Pointer point towards that New Node
// then make the Pointer either Head or Tail point to the New Node
// We can Remove Elements either at the Front or Back, the Process is Symetrical too. We make the Head or Tail Pointer point to the Node after or before it,
// then if the Pointer is not null we make that Node either Prev or Next Pointer point to null. Then we return the Value of the Removed Node.

class Deque {
public:
    struct Node{
        int data;
        Node *next;
        Node *prev;

        Node()
        : data(-1), next(nullptr), prev(nullptr)
        {
        }

        Node(int _data, Node *_next, Node *_prev)
        : data(_data), next(_next), prev(_prev)
        {
        }
    };

    Node *head, *tail;

    Deque()
    : head(nullptr), tail(nullptr)
    {
    }
    
    void push_back(int x){
        Node *node = new Node(x, nullptr, tail);
        if (tail != nullptr){
            tail->next = node;
        }
        tail = node;
        if (head == nullptr){
            head = node;
        }
    }

    void push_front(int x){
        Node *node = new Node(x, head, nullptr);
        if (head != nullptr){
            head->prev = node;
        }
        head = node;
        if (tail == nullptr){
            tail = node;
        }
    }
    
    int pop_back(){
        int data = 0;
        if (tail != nullptr){
            data = tail->data;
            tail = tail->prev;
            if (tail != nullptr){
                tail->next = nullptr;
            }
        }
        if (tail == nullptr){
            head = nullptr;
        }
        return data;
    }

    int pop_front(){
        int data = 0;
        if (head != nullptr){
            data = head->data;
            head = head->next;
            if (head != nullptr){
                head->prev = nullptr;
            }
        }
        if (head == nullptr){
            tail = nullptr;
        }
        return data;
    }
    
    int front(){
        if (head != nullptr){
            return head->data;
        }
        return 0; // Should return an exception
    }

    int back(){
        if (tail != nullptr){
            return tail->data;
        }
        return 0; // Should return an exception
    }
    
    bool empty(){
        return head == nullptr;
    }
};

#include <vector>

using namespace std;

// This is a very inefficient but straightforward implementation of a Queue
// We just add elements to a dynamic array, from the tail so to speak.
// And to remove elements we just increase an index that points to the front of the Queue.
// This will make the array containing the queue grow in size indefinitely. It works but its not great.

class ArrayQueue {
    vector<int> queue;
    int head;
public:
    ArrayQueue() {
        head = 0;
    }
    bool enqueue(int x) {
        queue.push_back(x);
        return true;
    }
    bool dequeue() {
        if (empty()) {
            return false;
        }
        head++;
        return true;
    }
    int front() {
        return queue[head];
    }
    bool empty() {
        return head >= queue.size();
    }
};

class MyCircularQueue {
    vector<int> queue;
    int head, tail;
public:
    MyCircularQueue(int k) {
        queue = vector<int>(k);
        head = tail = -1;
    }
    bool enQueue(int value) {
        if (tail < 0){
            head = tail = 0;
        }
        else{
            int p = tail;
            tail++;
            if (tail >= queue.size()){
                tail = 0;
            }
            if (tail == head){
                // Queue is full
                tail = p;
                return false;
            }
        }
        queue[tail] = value;
        return true;
    }
    bool deQueue() {
        if (head < 0){
            return false;
        }
        if (head == tail){
            head = tail = -1;
            return true;
        }
        head++;
        if (head >= queue.size()){
            head = 0;
        }
        return true;
    }
    int Front() {
        if (head < 0){
            // Queue is empty
            return -1;
        }
        return queue[head];
    }
    int Rear() {
        if (tail < 0){
            // Queue is empty
            return -1;
        }
        return queue[tail];
    }
    bool isEmpty() {
        return tail == -1;
    }
    bool isFull() {
        int v = tail + 1;
        if (v >= queue.size()){
            v = 0;
        }
        return v == head;
    }
};