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
        ListNode *p = head;
        while (p)
        {
            ptr.push_back(p);
            p = p->next;
        }
        ptr.push_back(NULL);
        if (ptr.size() - n - 1 == 0)
        {
            head = ptr[1];
        }
        else
        {
            ptr[ptr.size() - n - 2]->next = ptr[ptr.size() - n];
        }
        return head;
    }
};