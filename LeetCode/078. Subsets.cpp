class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>element;
        for (int i = 0; i <= nums.size(); i++)//依次处理集合含有0—nums.size()个元素
        {
            int posi = -1;
            solve(result, element, nums, posi, i);
        }
        return result;
    }
    void solve(vector<vector<int>>&result, vector<int>&element, vector<int>nums, int posi, int n)
    {
        if (element.size() == n)
        {
            result.push_back(element);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (i <= posi)continue;//posi记录上一层递归达到的位置
            element.push_back(nums[i]);
            solve(result, element, nums, i, n);
            element.pop_back();
        }
    }
};

//2
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>element;
        result.push_back(element);
        int start=0;
        solve(result,element,nums,start);
        return result;
    }
    void solve(vector<vector<int>>&result,vector<int>&element,vector<int>&nums,int start)
    {
        if(element.size()==nums.size())
            return;
        for(int i=start;i<nums.size();i++)
        {
            element.push_back(nums[i]);
            result.push_back(element);
            solve(result,element,nums,i+1);
            element.pop_back();
        }
    }
};

//3这个题蛮有意思的，可以直接从后遍历，遇到一个数就把所有子集加上该数组成新的子集，遍历完毕即是所有子集————leetcode热评
