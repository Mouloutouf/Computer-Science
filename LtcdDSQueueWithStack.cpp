#include <vector>
using namespace std;

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

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */