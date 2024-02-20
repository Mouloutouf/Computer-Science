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

// Given the head Node of a linked list, determine if there is a cycle in the List

// This is actually very easy, think of it as a racetrack with two cars. One is fast, the other is slow. If the race is in a straight line, then the fast car will just finish before the slow one.
// But if the race is a cycle, the fast car will eventually lap the slow one. This is how we know if the list contains a cycle. Check if the fast car laps the slow one.
// In other terms, have two pointers going through the linked list, the slow one goes through each node, while the fast one goes two nodes at a time.
// When both the fast and slow pointers reach the same node, we know there is a cycle.

class Solution {
public:

    bool hasCycle(ListNode *head)
    {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow)
                return true;
        }
        return false;
    }
};