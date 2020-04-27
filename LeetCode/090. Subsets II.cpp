class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>element;
        sort(nums.begin(), nums.end());//先对nums排序，避免出现集合的元素一样，但位置不同的情况
        for (int i = 0; i <= nums.size(); i++)//依次处理集合含有0—nums.size()个元素
        {
            int posi=-1;
            solve(result, element, nums, i,posi);
        }
        return result;
    }
    void solve(vector<vector<int>>&result, vector<int>&element, vector<int>nums, int n,int posi)
    {
        if (element.size() == n)
        {
            if(find(result.begin(),result.end(),element)==result.end())
                result.push_back(element);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (i <= posi)continue;//posi记录上一层递归的位置
            element.push_back(nums[i]);
            solve(result, element, nums, n,i);
            element.pop_back();
        }
    }
};

//2
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size=nums.size();
        vector<vector<int>>result;
        vector<int>element;
        result.push_back(element);
        dfs(result,nums,element,0);
        return result;
    }
    void dfs(vector<vector<int>>&result,vector<int>& nums,vector<int>&element,int start)
    {
        if(element.size()==nums.size())
            return;
        for(int i=start;i<nums.size();i++)
        {
            if(i!=start&&nums[i]==nums[i-1])
                continue;
            element.push_back(nums[i]);
            result.push_back(element);
            dfs(result,nums,element,i+1);
            element.pop_back();
        }
    }
};
