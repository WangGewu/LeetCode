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
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};


//2,bfs
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
    int maxDepth(TreeNode* root) {
        int max_d=0;
        if(root==NULL)return max_d;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            max_d++;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* current_p=q.front();q.pop();
                if(current_p->left)q.push(current_p->left);
                if(current_p->right)q.push(current_p->right);
            }
        }
        return max_d;
    }
};