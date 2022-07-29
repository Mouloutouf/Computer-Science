// Given the head of a singly linked list, return true if it is a palindrome.

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *main = head;
        int size = 0;
        while (main != nullptr){
            main = main->next;
            size++;
        }
        int median = size % 2 == 0 ? size / 2 : (size - 1) / 2;
        int count = 1;
        main = head;
        while (count < median){
            main = main->next;
            count++;
        }
        ListNode* prior = main;
        main = main->next;
        ListNode* start = main;
        while (main != nullptr){
            ListNode* rev = main->next;
            main->next = main->next->next; // No null check
            rev->next = start;
            prior->next = rev;
            start = rev;
            main = main->next;
        }
        ListNode* second = head;
        main = start;
        count = 1;
        while (count < median){
            if (main->val != second->val){
                return false;
            }
            count++;
        }
        return true;
    }
};