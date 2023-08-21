
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        ListNode *ptr1 = list1;
        ListNode *ptr2 = list2;
        ListNode *dummy = new ListNode();
        ListNode *ptr3 = dummy;
        while (ptr1 != nullptr && ptr2 != nullptr)
        {
            if (ptr1->val <= ptr2->val)
            {
                ptr3->next = ptr1;
                ptr1 = ptr1->next;
            }
            else
            {
                ptr3->next = ptr2;
                ptr2 = ptr2->next;
            }
            ptr3 = ptr3->next; // Move ptr3 forward after assigning the next node
        }
        while (ptr1 != nullptr)
        {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
            ptr3 = ptr3->next;
        }
        while (ptr2 != nullptr)
        {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
            ptr3 = ptr3->next;
        }
        ptr3->next = nullptr;
        return dummy->next;
    }
};