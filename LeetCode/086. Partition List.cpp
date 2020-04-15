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
    ListNode* partition(ListNode* head, int x) {
        ListNode* head1 = new ListNode(0);
        ListNode* head2 = new ListNode(0);
        ListNode* current1 = head1, *current2 = head2;
        ListNode* p = head;
        while (p)
        {
            if (p->val < x)
            {
                current1 = current1->next = p;
            }
            else
            {
                current2 = current2->next = p;
            }
            p = p->next;
        }
        current2->next = nullptr;//将不小于x的链表尾节点next置空
        current1->next = head2->next;//拼接两个链表
        return head1->next;
    }
};

//2
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* min_head=new ListNode(-1);
        ListNode* min_p=min_head;
        ListNode* max_head=new ListNode(-1);
        ListNode* max_p=max_head;
        ListNode* p=head;
        while(p)
        {
            if(p->val<x)
            {
                min_p->next=p;
                min_p=min_p->next;
            }
            else
            {
                max_p->next=p;
                max_p=max_p->next;
            }
            p=p->next;
        }
        max_p->next=NULL;//关键
        min_p->next=max_head->next;
        return min_head->next; 
    }
};
