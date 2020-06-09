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
    bool isBalanced(TreeNode* root) {
        if(solve(root)==-1)
            return false;
        else
            return true;
    }
    int solve(TreeNode* root)
    {
        if(root==NULL)return 0;
        int left=solve(root->left);
        int right=solve(root->right);
        if(left==-1||right==-1||abs(left-right)>1)
            return -1;
        else
            return max(left,right)+1;
    }
};