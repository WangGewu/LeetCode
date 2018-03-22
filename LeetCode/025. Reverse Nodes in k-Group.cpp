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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int num = 0;
        ListNode *p = head;
        while (p)
        {
            p = p->next;
            num++;
        }
        p = head;
        ListNode *x = new ListNode(-1);//����ͷ���
        x->next = head;
        head = x;
        ListNode *new_head = x->next, *t = x->next, *nowhead = x, *q;
        ListNode *temphead = x;
        int n = num / k;
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            p = t;
            nowhead = t;//���ζ������ͷ���
            q = p->next;
            int cnt = 1;
            while (cnt<k)
            {
                t = q->next;
                q->next = p;
                p = q;
                q = t;
                cnt++;
                flag = 1;
            }
            if (i == 0)
                new_head = p;
            if (flag)
            {
                temphead->next = p;//ǰһ�������β�ڵ������һ�������ͷ���
                temphead = nowhead;//����ǰһ�������β�ڵ�
            }
        }
        temphead->next = t;
        return new_head;
    }
};