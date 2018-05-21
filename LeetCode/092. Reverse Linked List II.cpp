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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (n == m)return head;
        ListNode *front, *temp, *p, *q, *s;
        ListNode* headnode = new ListNode(0);//ԭ�ش�������ʱ������һ��ͷ�����Է���ı���߽����������
        headnode->next = head;
        front = headnode;//��¼��Ҫ��ת��ǰһ���ڵ�
        n = n - m;
        while (--m)
            front = front->next;
        temp = front->next;//��¼��һ����ת�Ľڵ�
        p = temp;
        q = p->next;
        while (n--)
        {
            ListNode* s = q->next;
            q->next = p;
            p = q;
            q = s;
        }
        //ƴ��
        front->next = p;
        temp->next = q;
        return headnode->next;
    }
};