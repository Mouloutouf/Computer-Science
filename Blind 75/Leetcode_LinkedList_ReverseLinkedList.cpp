using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// EXPLANATION

// This is a classic problem of reversing a linked list.

// The solution is very obvious, only the implementation is a bit tedious, with keeping and replacing the right pointers in the right order.
// Read this carefully in order to understand each operation, since they are very hard to visualize.

class Solution {
public:

    ListNode* reverseList(ListNode* head)
    {
        ListNode* back = head;

        while (head != nullptr && head->next != nullptr)
        {
            ListNode* node = head->next;
            head->next = node->next;
            
            node->next = back;
            back = node;
        }

        return back;
    }
};