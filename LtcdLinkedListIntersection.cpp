// Given Two Linked Lists A and B, Find out if they Intersect and if so, at which Node.
// To solve this, we need to be able to compare two pointers, to find out if they are on the same List.
// But to do that, we need to be sure they both are at the same distance from the end of the list.
// Therefore we can make either of them go through either list, and when they reach the end, put them through the other list.
// That way, on their second run (once both pointers have switched to the other list), both pointers will be at same distance from the end

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA, *ptr2 = headB;
        int c = 0;
        while (true){
            if (c < 2){
                if (ptr1){
                    ptr1 = ptr1->next;
                }
                else{
                    c++;
                    ptr1 = headB;
                }
                if (ptr2){
                    ptr2 = ptr2->next;
                }
                else{
                    c++;
                    ptr2 = headA;
                }
            }
            else{
                if (ptr1 == ptr2){
                    return ptr1;
                }
                if (ptr1 && ptr2){
                    ptr1 = ptr1->next;
                    ptr2 = ptr2->next;
                }
                else{
                    return nullptr;
                }
            }
        }
    }
};

class OtherSolution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA, *ptr2 = headB;
        int c = 0;
        while (true){
            if (ptr1 == ptr2)
                return ptr1;
            if (ptr1)
                ptr1 = ptr1->next;
            else{
                if (c > 1) return nullptr;
                c++;
                ptr1 = headB;
            }
            if (ptr2)
                ptr2 = ptr2->next;
            else{
                if (c > 1) return nullptr;
                c++;
                ptr2 = headA;
            }
        }
    }
};

// I just Do Not Understand this Solution. There is No Null Check, No Condition to Break out of the Loop if there is no Intersection.
// How the fuck does this not create an Infinite Loop. I don't understand.

class WhatTheActualFuckSolution {
    public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA, *ptr2 = headB;
        while (ptr1 != ptr2)
        {
            ptr1 = (ptr1 == nullptr) ? headB : ptr1->next;
            ptr2 = (ptr2 == nullptr) ? headA : ptr2->next;
        }
        return ptr2;
    }
};