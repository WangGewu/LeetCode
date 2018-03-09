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
		int flag = 0;//记录进位
		int k = (l1->val + l2->val) % 10;
		if (l1->val + l2->val >= 10)flag = 1;
		ListNode *head = new ListNode(k);
		ListNode *front = head;
		ListNode *p = l1->next, *q = l2->next;
		while (p&&q)
		{
			ListNode *temp = new ListNode((p->val + q->val + flag) % 10);
			front->next = temp;
			front = temp;
			if (p->val + q->val + flag >= 10)
				flag = 1;
			else
				flag = 0;
			p = p->next; q = q->next;
		}
		while (p)
		{
			ListNode *temp = new ListNode((p->val + flag) % 10);
			front->next = temp;
			front = temp;
			if (p->val + flag >= 10)
				flag = 1;
			else
				flag = 0;
			p = p->next;
		}
		while (q)
		{
			ListNode *temp = new ListNode((q->val + flag) % 10);
			front->next = temp;
			front = temp;
			if (q->val + flag >= 10)
				flag = 1;
			else
				flag = 0;
			q = q->next;
		}
		if (flag)
		{
			ListNode *temp = new ListNode(1);
			front->next = temp;
		}
		return head;
	}
};
