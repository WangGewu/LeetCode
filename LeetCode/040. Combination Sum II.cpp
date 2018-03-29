class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>result;
        vector<int>element;
        solve(result, element, 0, target, candidates);
        return result;
    }
    void solve(vector<vector<int>>&v, vector<int>&element, int n, int sum, vector<int>&candidates)
    {
        if (!sum&&find(v.begin(), v.end(), element) == v.end())//避免重复
        {
            v.push_back(element);
            return;
        }
        for (int i = n; i < candidates.size() && sum >= candidates[i]; i++)//目前元素值小于等于sum，继续循环
        {
            element.push_back(candidates[i]);
            solve(v, element, i + 1, sum - candidates[i], candidates);//递归
            element.pop_back();//回溯
        }
    }
};