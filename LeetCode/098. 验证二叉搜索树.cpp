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
    bool isValidBST(TreeNode* root) {
        if(root==NULL)return true;
        if((!isValidBST(root->left))||(!isValidBST(root->right))) //左、右子树至少一个不是二叉搜索树
            return false;
        if(root->left) 
        {
            TreeNode* p=root->left;
            while(p->right) p=p->right; //找到左子树的最大值
            int max=p->val;
            if(root->val<=max)return false;
        }
        if(root->right)
        {
            TreeNode* p=root->right;
            while(p->left)p=p->left; //找到右子树的最小值
            int min=p->val;
            if(root->val>=min)return false;
        }
        return true;
    }
};

//2 中序遍历为递增数组