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
    vector<vector<int>>result;
    vector<int>temp;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        solve(root,sum,result);
        return result;
    }
    void solve(TreeNode* root, int sum,vector<vector<int>>&result)
    {
        if(root==NULL)return;
        temp.push_back(root->val);
        if(root->left==NULL&&root->right==NULL)
        {
            if(sum-root->val==0)
                result.push_back(temp);
        }
        else
        {
            solve(root->left,sum-root->val,result);
            solve(root->right,sum-root->val,result);
        }
        temp.pop_back();
    }
};