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
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int>src;
        ListNode* p = head;
        while (p)
        {
            src.push_back(p->val);
            p = p->next;
        }
        int size = src.size();
        vector<int>dst(size, 0);
        for (int i = 0; i < size; ++i)
        {
            dst[(i + k) % size] = src[i];
        }
        p = head;
        int cnt = 0;
        while (p)
        {
            p->val = dst[cnt++];
            p = p->next;
        }
        return head;
    }
};

//2
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* old_head = head,*old_end=NULL;
        ListNode* p=head;
        int length=0;
        while(p)
        {
            length++;
            if(!p->next)
                old_end=p;
            p=p->next;
        }
        if(length==0||k%length==0)
            head=old_head;
        else
        {
            p=old_head;
            for(int i=0;i<length-(k%length)-1;i++)
                p=p->next;
            head = p->next;
            p->next=NULL;
            old_end->next=old_head;
        }
        return head;
    }
};
