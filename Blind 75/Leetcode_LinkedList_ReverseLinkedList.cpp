using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// TODO

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