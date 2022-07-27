// Given a Linked List and a Value, Remove all Nodes of the same Value

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *cur = head, *prev = nullptr, *nxt = nullptr;
        while (cur != nullptr){
            if (cur->val == val){
                // TODO
            }
        }
    }
};