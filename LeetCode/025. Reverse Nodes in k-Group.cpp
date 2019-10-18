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
        ListNode *p = head, *q, *temp, *rear = head, *front, *rear2;
        int cnt = 0;
        int num = 0;//记录节点数
        while (p)
        {
            p = p->next;
            num++;
        }
        int n = num / k;//翻转次数
        if(!n)
            return head;
        p = head;
        //翻转
        while (n)
        {
            q = p->next;
            rear2 = p;//记录当下的尾节点
            for (int i = 0; i<k - 1; i++)
            {
                temp = q->next;
                q->next = p;
                p = q;
                q = temp;
            }
            front = p;//记录当下的头结点
            if (cnt>0)
            {
                rear->next = front;//上一次的尾节点接上这次的头结点
                rear = rear2;
            }
            else
                head = front;
            p = q;
            cnt++;
            n--;
        }
        rear2->next = p;//接上剩余的节点
        return head;
    }
};
