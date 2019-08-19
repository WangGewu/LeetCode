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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int flag=0;
        ListNode *head=new ListNode(0);
        ListNode *current_p=head;
        ListNode *new_value;
        while(l1&&l2)
        {
            int value=(l1->val+l2->val+flag)%10;
            if(l1->val+l2->val+flag>=10)
                flag=1;
            else
                flag=0;
            new_value=new ListNode(value);
            current_p->next=new_value;
            current_p=new_value;
            l1=l1->next;l2=l2->next;
        }
        while(l1)
        {
            new_value=new ListNode((flag+l1->val)%10);
            if(flag+l1->val>=10)
                flag=1;
            else
                flag=0;
            current_p->next=new_value;
            current_p=new_value;
            l1=l1->next;
        }
        while(l2)
        {
            new_value=new ListNode((flag+l2->val)%10);
            if(flag+l2->val>=10)
                flag=1;
            else
                flag=0;
            current_p->next=new_value;
            current_p=new_value;
            l2=l2->next;
        }
        if(flag==1)
        {
            new_value=new ListNode(1);
            current_p->next=new_value;
        }
        return  head->next;
    }
};
