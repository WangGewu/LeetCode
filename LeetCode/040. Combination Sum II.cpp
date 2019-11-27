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

//2刷
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>result;
        vector<int>current_result;
        int pos=0;
        solve(result,candidates,current_result,pos,target);
        //set<vector<int>> st(result.begin(), result.end());
        //result.assign(st.begin(), st.end());
        return result;
    }
    void solve(vector<vector<int>>& result,vector<int>candidates,vector<int>current_result,int pos,int target)
    {
        int last=-1;
        if(target==0)
            {   result.push_back(current_result);
                return;
            }
        else if(target<0)
        {
            return ;
        }
        for(int i=pos;i<candidates.size();i++)
        {   
            if(candidates[i]==last)
                continue;
            current_result.push_back(candidates[i]);
            solve(result,candidates,current_result,i+1,target-candidates[i]);
            last=candidates[i];
            current_result.pop_back();
        }
    }
};
