// Given the Head Node of a Linked List, Determine if there is a Cycle in the List, and Return the Node on which the Cycle Starts
// This uses the Floyd's Algorithm which ensures that if we do Find a Cycle in our List, by using the Two-Pointer Technique, we can Trace Back where the Start Node is.
// When using the Two-Pointer Technique, we know there is a Cycle once our Two Pointers meet. When using Floyd's Algorithm, we can use this Meeting Node to Find the Start.
// Floyd's says that the Start Node of the Cycle is at exactly the same distance from the Meeting Point and the Head.
// Therefore, by taking our Two Pointers again, leaving one at the Meeting Node, and putting the Other at the Head, and making them both cycle One Node at a time,
// we know that when they meet, we will Find the Start Node of the Cycle.

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Here I use the Same Loop for both Cycles, and use a Boolean r, to indicate in which cycle I'm in.

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr)
            return nullptr;
        ListNode *fast, *slow;
        fast = slow = head;
        bool r = false;
        while (fast != nullptr && fast->next != nullptr){
            if (r && fast == slow){
                return fast;
            }
            fast = r ? fast->next : fast->next->next;
            slow = slow->next;
            if (fast == slow){
                if (!r){
                    r = true;
                    slow = head;
                }
                else{
                    return fast;
                }
            }
        }
        return nullptr;
    }
};

// Here we make Two Cycles. The First one to Detect a Loop in the List. When we do, we Break, and then Check the Condition of the Break.
// If the Loop Broke because of a null pointer, then there is no Loop, we return.
// Otherwise, we did find a Cycle, so we continue.
// We then assign head to the slow pointer, and proceed with a Second Cycle, that will break when both pointers are on the same Node.
// When we do, we just return any of the two pointers (since they are identical) which will return the Start Node.

class OtherSolution{
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (fast == nullptr || fast->next == nullptr)
            return nullptr;
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};