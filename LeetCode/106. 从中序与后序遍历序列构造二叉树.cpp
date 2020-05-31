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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int in_start=0,post_start=0,len=inorder.size();
        return solve(inorder,postorder,in_start,post_start,len);
    }
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int in_start,int post_start,int len)
    {
        if(len<=0)return NULL;
        TreeNode *current_root=new TreeNode(postorder[post_start+len-1]);
        int posi=find(inorder.begin()+in_start,inorder.begin()+in_start+len,postorder[post_start+len-1])-inorder.begin();
        int left_len=posi-in_start;
        current_root->left=solve(inorder,postorder,in_start,post_start,left_len);
        current_root->right=solve(inorder,postorder,posi+1,post_start+left_len,len-left_len-1);
        return current_root;
    }
};