// Given a Linked List and a Value, Remove all Nodes of the same Value

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Quite straightforward. I just make a pointer Cur loop through the entire list, with another pointer Prev following it.
// When I encounter a value that matches, I delete it. I check if Prev is null before. If it is, then I am deleting head, so I replace head.
// Otherwise, I am just deleting a node of the list, so I make Prev point to the next node of Cur, to remove the current node.
// Then I make Cur progress to the next node of the list.
// Note : I only make Prev progress towards Cur when we do not find a value that matches. This is because when deleting, the node of Cur is removed,
// so it only makes sense to make Cur progress, so that it points at the next node, since Prev is already pointing at the node behind the next node.

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *cur = head, *prev = nullptr;
        while (cur != nullptr){
            if (cur->val == val){
                if (prev != nullptr){
                    prev->next = cur->next;
                }
                else{
                    head = cur->next;
                }
            }
            else{
                prev = cur;
            }
            cur = cur->next;
        }
        return head;
    }
};