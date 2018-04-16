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