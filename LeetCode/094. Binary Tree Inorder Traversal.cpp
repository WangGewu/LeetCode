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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>result;
        solve(result, root);
        return result;
    }
    void solve(vector<int>&result, TreeNode* root)
    {
        if (root)
        {
            solve(result, root->left);
            result.push_back(root->val);
            solve(result, root->right);
        }
    }
};