class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>result;
        vector<int>element;
        solve(result, element, 0, target, candidates);
        return result;
    }
    void solve(vector<vector<int>>&v, vector<int>&element, int n, int sum, vector<int>&candidates)
    {
        if (!sum)
        {
            v.push_back(element);
            return;
        }
        for (int i = n; i < candidates.size() && sum >= candidates[i]; i++)//目前元素值小于等于sum，继续循环
        {
            element.push_back(candidates[i]);
            solve(v, element, i, sum - candidates[i], candidates);//递归
            element.pop_back();//回溯
        }
    }
};

//2刷
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>current_result;
        int current_pos=0;
        solve(result,current_result,candidates,target,current_pos);
        return result;
    }
    void solve(vector<vector<int>>& result,vector<int>&current_result,vector<int>& candidates,int target,int current_pos)
    {
        if(target==0)
        {
            result.push_back(current_result);
            return;
        }
        else if(target<0)
            return;
        else{
            for(int i=current_pos;i<candidates.size();i++)
            {
                current_result.push_back(candidates[i]);
                solve(result,current_result,candidates,target-candidates[i],i);
                current_result.pop_back();
            }
        }
    }
};
