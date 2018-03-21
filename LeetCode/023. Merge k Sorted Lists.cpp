class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = NULL;
        head = dfs(lists);
        return head;
    }
    //递归解决每个链表
    ListNode* dfs(vector<ListNode*>& lists) {
        int minPos;
        int min = 99999999;
        for (int i = 0; i<lists.size(); i++)
        {
            if (lists[i] == NULL)
                continue;
            if (lists[i]->val < min)
            {
                min = lists[i]->val;
                minPos = i;
            }
        }
        if (min == 99999999)//所有链表都处理完后返回
            return NULL;
        else
        {
            lists[minPos] = lists[minPos]->next;//修改lists
            ListNode* p = new ListNode(min);
            p->next = dfs(lists);//继续递归
            return p;
        }
    }
};