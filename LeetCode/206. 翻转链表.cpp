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
    ListNode* reverseList(ListNode* head) {
        if(!head)return head;
        ListNode *p=head,*q=head->next,*k;
        while(p&&q)
        {
            k=q->next;
            q->next=p;
            p=q;
            q=k;
        }
        head->next=NULL;
        return p;
    }
};

递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* new_head=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return new_head;
    }
};