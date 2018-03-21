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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* p = head;
        ListNode* q = p->next;
        ListNode* h = q;
        while (p&&q)
        {
            p->next = q->next;
            ListNode* t = p;
            q->next = p;
            if (p->next)
            {
                p = p->next;
            }
            else
                return h;
            if (p->next)
            {
                q = p->next;
                t->next = q;
            }
            else
                return h;
        }
    }
};