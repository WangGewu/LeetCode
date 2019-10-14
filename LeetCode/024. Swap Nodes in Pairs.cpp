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
        return h;
    }
};

//方法二
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
        if(!head)
            return head;
        ListNode* p1=head;
        ListNode* p2=nullptr;
        vector<ListNode*>ptr;
        while(p1)
        {
            p2=p1->next;
            if(p2)
            {
                ptr.push_back(p2);
                ptr.push_back(p1);
                p1=p2->next;
            }
            else
            {
                ptr.push_back(p1);
                break;
            }
        }
        for(int i=0;i<ptr.size()-1;i++)
        {
            ptr[i]->next=ptr[i+1];
        }
        if(ptr.size()-1!=0)
            ptr[ptr.size()-1]->next=nullptr;
        return ptr[0];
    }
};
