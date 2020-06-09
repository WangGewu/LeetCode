/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* low_p=head;
        ListNode* fast_p=head;
        ListNode* pre_p=NULL;
        TreeNode* current_root;
        while(fast_p!=NULL&&fast_p->next!=NULL)
        {
            pre_p=low_p;
            low_p=low_p->next;
            fast_p=fast_p->next->next;
        }
        if(pre_p==NULL)
        {
            if(head==NULL)
                current_root=NULL;
            else
                current_root=new TreeNode(low_p->val);
        }
        else
        {
            current_root=new TreeNode(low_p->val);
            pre_p->next=NULL;
            current_root->left=sortedListToBST(head);
            current_root->right=sortedListToBST(low_p->next);
        }
        return current_root;
    }
};