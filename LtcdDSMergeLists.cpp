struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *first = list1, *second = list2;
        ListNode *previous;
        while (second != nullptr){
            ListNode *insert = second;
            second = second->next;
            if (first->next == nullptr){
                
            }
            if (first->val >= insert->val){
                insert->next = first;
                if (previous != nullptr){
                    previous->next = insert;
                }
                previous = first;
                first = first->next;
            }
            else{
                ListNode *after = first->next;
                first->next = insert;
                insert->next = after;
                previous = insert;
                first = after;
            }
        }
    }
};