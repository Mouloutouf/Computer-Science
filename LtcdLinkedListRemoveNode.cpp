// Given A Linked List, Remove the Nth Node from the End of the List.

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Here we Loop through the List with Two Pointers, following one another.
// Since we want to remove a certain node in the List, at N distance from the End, we make the First Pointer loop through the entire List, while
// the Second Pointer loops through that same List but with a gap of N nodes from the First Pointer. That way, when First Pointer reaches the End of the List
// Second Pointer will be pointing to the Node we want to Remove.
// Then we exit the Loop, and Remove the Node.
// For that we take the Node that is just prior to the Node we want to Remove, and make this Node point to the Node that is after the Node we want to Remove.
// An Exception is made for when we are removing the Head Node. We just replace it with the Node that is after it, since there is no Node prior to it.
// The way we Detect that we are removing Head is by comparing the N distance to the amount of Steps it took to complete the Loop. If they are equal, then we are removing the
// first Node of the List, e.g. Head.

class BestSolution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first = head, *second = nullptr, *previous = nullptr;
        int i = 0;
        while (first != nullptr){
            first = first->next;
            if (second != nullptr){
                previous = second;
                second = second->next;
            }
            i++;
            if (i == n){
                second = head;
            }
        }
        if (i <= n){
            head = second->next;
        }
        else{
            previous->next = second->next;
        }
        return head;
    }
};