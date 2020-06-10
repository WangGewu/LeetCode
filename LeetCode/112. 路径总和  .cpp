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
    bool hasPathSum(TreeNode* root, int sum) {
        bool flag=false;
        solve(root,sum,0,flag);
        return flag;
    }
    void solve(TreeNode* root, int sum,int pre,bool &flag)
    {
        if(root==NULL)return;
        int current_val=root->val+pre;
        if(root->left==NULL&&root->right==NULL)
            flag=(current_val==sum?true:false);
        if(flag==false)
            solve(root->left,sum,current_val,flag);
        if(flag==false)
            solve(root->right,sum,current_val,flag);
    }
};