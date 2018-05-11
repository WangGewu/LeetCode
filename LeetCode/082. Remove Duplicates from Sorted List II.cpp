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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *l, *p, *q;
        ListNode *currentPtr = new ListNode(1);
        ListNode* newHead = currentPtr;
        l = head;
        if (!l || !l->next)//������0��1���ڵ�����
            return head;
        p = l->next;
        q = p->next;
        if (!q)//�����������ڵ�����
        {
            if (p->val != l->val)
                return head;
        }
        while (l&&p&&q)
        {
            if (l == head&&l->val != p->val)
            {
                currentPtr->next = new ListNode(l->val);
                currentPtr = currentPtr->next;
            }
            if (l->val != p->val&&p->val != q->val)
            {
                currentPtr->next = new ListNode(p->val);
                currentPtr = currentPtr->next;
            }
            l = p; p = q; q = q->next;
        }
        if (p->val != l->val)//�������һ��Ԫ��
            currentPtr->next = new ListNode(p->val);
        return newHead->next;
    }
};