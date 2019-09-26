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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*>ptr;
        ListNode* p=head;
        while(p)
        {
            ptr.push_back(p);
            p=p->next;
        }
        //精髓
        ptr.push_back(nullptr);
        int size=ptr.size();
        if(n==size-1)
            head=ptr[1];
        else
            ptr[size-n-2]->next=ptr[size-n];
        return head;
    }
};
