// Given A Linked List, Reverse it then return it.

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *current = head, *newHead = head;
        while (current != nullptr && current->next != nullptr){
            ListNode *first = current->next;
            ListNode *second = first->next;
            first->next = newHead;
            current->next = second;
            newHead = first;
        }
        return newHead;
    }
};

class OtherSolution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head, *nxt = nullptr, *prev = nullptr;
        while (cur != nullptr){
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
};

class BetterSolution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head, *newHead = head;
        while (cur != nullptr && cur->next != nullptr){
            ListNode *node = cur->next;
            cur->next = node->next;
            node->next = newHead;
            newHead = node;
        }
        return newHead;
    }
};