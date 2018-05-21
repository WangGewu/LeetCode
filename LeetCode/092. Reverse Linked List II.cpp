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
        ListNode* headnode = new ListNode(0);//原地处理链表时，创建一个头结点可以方便的避免边界情况！！！
        headnode->next = head;
        front = headnode;//记录需要翻转的前一个节点
        n = n - m;
        while (--m)
            front = front->next;
        temp = front->next;//记录第一个翻转的节点
        p = temp;
        q = p->next;
        while (n--)
        {
            ListNode* s = q->next;
            q->next = p;
            p = q;
            q = s;
        }
        //拼接
        front->next = p;
        temp->next = q;
        return headnode->next;
    }
};