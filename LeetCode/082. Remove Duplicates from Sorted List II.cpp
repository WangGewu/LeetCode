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
        if (!l || !l->next)//处理有0、1个节点的情况
            return head;
        p = l->next;
        q = p->next;
        if (!q)//处理有两个节点的情况
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
        if (p->val != l->val)//处理最后一个元素
            currentPtr->next = new ListNode(p->val);
        return newHead->next;
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)//0个节点
            return head;
        else if(head->next==NULL)//1个节点
            return head;
        ListNode* p=head;
        ListNode* newhead=new ListNode(-1);
        ListNode* current=newhead;
        if(p->next->val!=p->val)//处理第一个节点
        {
            current->next=p;
            current=current->next;
        }
        while(p->next->next)
        {
            ListNode* left=p;
            ListNode* mid=p->next;
            ListNode* right=p->next->next;
            if(left->val!=mid->val&&mid->val!=right->val)
            {    
                current->next=mid;
                current=current->next;
            }
            p=p->next;
        }
        if(p->next->val!=p->val)//处理最后一个节点
        {    
            current->next=p->next;
            current=current->next;
        }
        current->next=NULL;
        return newhead->next;
    }
};
