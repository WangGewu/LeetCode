/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* p = head;
        while (l1&&l2)
        {
            if (l1->val <= l2->val)
            {
                ListNode* node = new ListNode(l1->val);
                p->next = node;
                p = node;
                l1 = l1->next;
            }
            else
            {
                ListNode* node = new ListNode(l2->val);
                p->next = node;
                p = node;
                l2 = l2->next;
            }
        }
        while (l1)
        {
            ListNode* node = new ListNode(l1->val);
            p->next = node;
            p = node;
            l1 = l1->next;
        }
        while (l2)
        {
            ListNode* node = new ListNode(l2->val);
            p->next = node;
            p = node;
            l2 = l2->next;
        }
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
};