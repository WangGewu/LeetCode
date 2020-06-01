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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>result;
        if(root==NULL)return result;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int current_size=q.size();
            vector<int>temp;
            for(int i=0;i<current_size;i++)
            {
                TreeNode* current_p=q.front();q.pop();
                temp.push_back(current_p->val);
                if(current_p->left)q.push(current_p->left);
                if(current_p->right)q.push(current_p->right);
            }
            result.push_back(temp);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};