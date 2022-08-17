#define OLD

#include <vector>
using namespace std;

// Broken Implementation Does not Work

#ifndef OLD
class MyQueue {
public:
    vector<int> values;
    int *in, *out;
    
    MyQueue() {
        values = vector<int>();
        in = out = nullptr;
    }
    
    void push(int x) {
        values.push_back(x);
        in = &values.back();
        if (values.size() == 1){
            out = in;
        }
    }
    
    int pop() {
        int val = *out;
        ++out;
        return val;
    }
    
    int peek() {
        if (out != nullptr){
            return *out;
        }
        return 0;
    }
    
    bool empty() {
        return out == nullptr;
    }
};
#endif

// Very Fast and Cheap Memory
// Using Linked List for Queue Design is Very Efficient

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
    
    void push(int x) {
        Node *node = new Node(x, nullptr);
        if (tail != nullptr){
            tail->next = node;
        }
        tail = node;
        if (head == nullptr){
            head = node;
        }
    }
    
    int pop() {
        int data = head->data;
        if (head != nullptr){
            head = head->next;
        }
        if (head == nullptr){
            tail = nullptr;
        }
        return data;
    }
    
    int peek() {
        if (head != nullptr){
            return head->data;
        }
        return 0; // Should return an exception
    }
    
    bool empty() {
        return head == nullptr;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */