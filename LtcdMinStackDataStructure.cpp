#include <limits>

// Implementation of a Min Stack. A specific Stack in which you can retrieve the minimum value of the stack in O(1) time.
// All operations on this Min Stack are supposed to take O(1) time. So I was obligated to use a linked list design, as no resize would be allowed.
// In order to make sure we retrieve the minimum value in O(1), all nodes in the stack have a value and a min value.
// This min value represents the minimum value for all the nodes prior or equal to the node. As such, when we remove values from the stack, we do not need to update the min value.

// For some reason LeetCode gets a null ref when running the getMin method, on a line that is literally right after a null check. Go figure.
// Even after removing the null check (since Leetcode actually always runs this method with a non null stack), same problem. I have no idea why it throws.

struct Node
{
    Node(int val, int m, Node* n)
        : value(val), min(m), next(n)
    {
    }
    
    int value;
    int min;
    
    Node* next;
};

class MinStack {
public:
    MinStack()
    {
    }

    void push(int val)
    {
        int min = val;
        if (base != nullptr)
            min = getMin();
        if (val < min)
            min = val;
        Node* cur = base;
        base = new Node(val, min, cur);
    }
    void pop()
    {
        Node* cur = base;
        base = cur->next;
        // null-handling
        delete cur;
    }
    int top()
    {
        return base->value;
        // null-handling
    }
    int getMin()
    {
        return base->min;
        // null-handling
    }

private:
    Node* base;
};