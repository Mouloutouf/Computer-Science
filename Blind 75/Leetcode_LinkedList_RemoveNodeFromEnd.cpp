using namespace std;

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// EXPLANATION

// Given A Linked List, Remove the Nth Node from the End of the List.

// Here we Loop through the list with two pointers, following one another.
// Since we want to remove a certain node in the list, at n distance from the end, we make the first pointer loop through the entire list, while
// the second pointer loops through that same list but with a gap of n nodes from the first pointer. That way, when the first pointer reaches the end of the list
// the second Pointer will be pointing to the node we want to remove.
// We can then exit the Loop, and remove that node.
// For that we take the node that is just prior to the node we want to remove, and make this node point to the node that is after the node we want to remove.

// An exception is made for when we are removing the head node. We just replace it with the node that is after it, since there is no node prior to it.
// The way we detect that we are removing head is by comparing the n distance to the amount i of steps it took to complete the loop.
// If they are equal, then we are removing the first node of the list, e.g. head.

class Solution {
public:

    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* first = head;
        ListNode* second = nullptr;

        ListNode* previous = nullptr;

        int i = 0;

        while (first != nullptr)
        {
            first = first->next;

            if (second != nullptr)
            {
                previous = second;
                second = second->next;
            }

            i++;

            if (i == n)
                second = head;
        }

        if (i <= n)
            head = second->next;
        else
            previous->next = second->next;

        return head;
    }
};