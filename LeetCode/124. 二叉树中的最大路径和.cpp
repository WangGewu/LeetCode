/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //注意最后返回
class Solution {
public:
    int result=INT_MIN;
    int maxPathSum(TreeNode* root) {
        get_max(root);
        return result;
    }
    int get_max(TreeNode* root)
    {
        if(root==NULL)return 0;
        int current_max=root->val;
        int left=max(0,get_max(root->left));
        int right=max(0,get_max(root->right));
        current_max=left+right+current_max;
        result=max(current_max,result);
        return max(left,right)+root->val;

    }
};