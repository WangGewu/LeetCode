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
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        else return ismirror(root->left,root->right);
    }
    bool ismirror(TreeNode* l,TreeNode* r)
    {
        if(l&&r)
            if(l->val==r->val)
                return ismirror(l->left,r->right)&&ismirror(l->right,r->left);
            else
                return false;
        else if(l==NULL&&r==NULL)
            return true;
        else
            return false;
    }
};