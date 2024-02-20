#include <algorithm>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// TODO

class Solution {
public:

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* result = new ListNode();
        ListNode* current = result;

        while (list1 != nullptr || list2 != nullptr)
        {
            if (list2 == nullptr)
            {
                current->next = list1;
                break;
            }
            else  if (list1 == nullptr)
            {
                current->next = list2;
                break;
            }
            else if (list1->val <= list2->val)
            {
                current->next = list1;
                list1 = list1->next;
            }
            else
            {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        ListNode* dummy = result;
        result = result->next;
        delete dummy;

        return result;
    }
};

class RecursiveSolution {
public:

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (list1 == nullptr || list2 == nullptr)
            return list1 != nullptr ? list1 : list2;
        
        if (list1->val > list2->val)
            swap(list1, list2);

        list1->next = mergeTwoLists(list1->next, list2);

        return list1;
    }
};
