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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(nums,0,nums.size()-1);
    }
    TreeNode* solve(vector<int>&nums,int start,int end)
    {
        if(end<start)return NULL;
        int mid=start+(end-start)/2;
        TreeNode *current_root=new TreeNode(nums[mid]);
        current_root->left=solve(nums,start,mid-1);
        current_root->right=solve(nums,mid+1,end);
        return current_root;
    }
};