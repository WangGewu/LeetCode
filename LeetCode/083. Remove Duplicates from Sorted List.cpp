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
        ListNode* newHead;
        ListNode *currentPtr = new ListNode(1);
        newHead = currentPtr;
        ListNode *p = head;
        int flag = 0;
        while (p)
        {
            if (p == head || p->val != currentPtr->val)
            {
                ListNode* temp = new ListNode(p->val);
                currentPtr->next = temp;
                currentPtr = currentPtr->next;
            }
            p = p->next;
        }
        return newHead->next;
    }
};