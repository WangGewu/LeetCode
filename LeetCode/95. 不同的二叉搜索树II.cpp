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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*>result;
        if(n==0)return result;
        result=solve(1,n);
        return result;
    }
    vector<TreeNode*> solve(int left,int right) {
        vector<TreeNode*>result;
        if(right==left)
        {
            TreeNode* root=new TreeNode(left);
            result.push_back(root);
            return result;
        }
        if(left>right)result.push_back(NULL);
        for(int i=left;i<=right;i++)
        {
            vector<TreeNode*>left_node = solve(left,i-1);
            vector<TreeNode*>right_node = solve(i+1,right);
            for(int j=0;j<left_node.size();j++)
                for(int k=0;k<right_node.size();k++)
                {
                    TreeNode* root=new TreeNode(i);
                    root->left=left_node[j];
                    root->right=right_node[k];
                    result.push_back(root);
                }
        }
        return result;
    }
};