// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *oddLast = head, *evenHead = head->next, *evenLast = head->next, *current = head->next;
        int i = 2;
        while (current != nullptr){
            if (i % 2 != 0){
                evenLast->next = current->next;
                current->next = evenHead;
                oddLast->next = current;
                oddLast = current;
                evenLast = evenLast->next;
                current = evenLast;
            }
            else{
                current = current->next;
            }
            i++;
        }
        return head;
    }
};

// Make All Odd Nodes point to each other, as well as All Even Nodes
// Save the First Even Node, then at the end, make the Last Odd Node point to the First Even Node
// Return the Reordered List

class BetterSolution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr){
            return nullptr;
        }
        ListNode *odd = head, *even = head->next, *evenHead = head->next;
        while (even && even->next){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};