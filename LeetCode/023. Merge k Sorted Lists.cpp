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


//第二种递归法
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=new ListNode(0);
        solution(lists,head);
        return head->next;
    }
    void solution(vector<ListNode*>& list,ListNode* rear)
    {
        int min=999999;
        int index=-1;
        for(int i=0;i<list.size();i++)
        {
            if(list[i]!=nullptr&&list[i]->val<min)
            {
                min=list[i]->val;
                index=i;
            }
        }
        if(min==999999)
            return;
        else
        {
            ListNode* element=new ListNode(min);
            rear->next=element;
            list[index]=list[index]->next;
            solution(list,element);
        } 
    }
};
