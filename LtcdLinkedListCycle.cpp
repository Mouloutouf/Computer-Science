// Given the Head Node of a Linked List, Determine if there is a Cycle in the List
// At Several Steps in the Solution, I Check for NULL to see if the List Stops. If it does, then there is no Cycle
// Otherwise, I use Two Pointers to Check for the Cycle. I have a First Pointer that moves One Node each Step,
// and a Second Pointer that moves Two Nodes each Step. That way, if the List does Cycle, there will be a Step on which
// both Pointers will be on the Same Node. While both Pointers are on Different Nodes, we continue to Cycle until eventually, an equality is found

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p1 = head;
        ListNode *p2;
        if (head == nullptr){
            return false;
        }
        p2 = head->next;
        while (p1 != p2){
            if (p2 == nullptr || p1 == nullptr){
                return false;
            }
            else{
                p2 = p2->next;
                if (p2 == nullptr){
                    return false;
                }
                p2 = p2->next;
                p1 = p1->next;
            }
        }
        return true;
    }
};

// Here, While the Fast Pointer Has Not Found an End to the List, we Continue
// Every time we increment our Pointers we check for Equality. If it is Found, the List has a Cycle

class OtherSolution{
public:
    bool hasCycle(ListNode *head){
        if (head == nullptr)
            return false;
        ListNode *fast, *slow;
        fast = slow = head;
        while (fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        return false;
    }
};