/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//中序遍历

class Solution {
public:
    TreeNode *t1=nullptr,*t2=nullptr,*pre=nullptr;
    void recoverTree(TreeNode* root) {
        inorder(root);
        int temp=t1->val;
        t1->val=t2->val;
        t2->val=temp;
    }
    void inorder(TreeNode* root)
    {
        if(root==nullptr)return;
        inorder(root->left);
        if(pre&&root->val<pre->val)//说明第一对的前一个node和第二对的后一个node需要交换
        {
            if(t1==nullptr)t1=pre;
            t2=root;
        }
        pre=root;
        inorder(root->right);
    }
};