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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre_start=0,in_start=0,len=inorder.size();
        return solve(preorder,inorder,pre_start,in_start,len);
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int pre_start,int in_start,int len)
    {
        if(len<=0)return NULL;
        TreeNode* current_root=new TreeNode(preorder[pre_start]);
        int posi=find(inorder.begin()+in_start,inorder.begin()+in_start+len,preorder[pre_start])-inorder.begin();
        int left_len=posi-in_start; //左子树长度
        int right_len=len-left_len-1; //右子树长度
        current_root->left=solve(preorder,inorder,pre_start+1,in_start,left_len);
        current_root->right=solve(preorder,inorder,pre_start+1+left_len,posi+1,right_len);
        return current_root;
    }

};