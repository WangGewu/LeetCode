class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>position;
        vector<int>element;
        solve(result,nums,position,element);
        return result;
    }
    void solve(vector<vector<int>>&result,vector<int>&nums,vector<int>&position,vector<int>&element)
    {
        if(element.size()==nums.size())
        {
            result.push_back(element);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(find(position.begin(),position.end(),i)!=position.end())
                continue;
            position.push_back(i);
            element.push_back(nums[i]);
            solve(result,nums,position,element);
            position.pop_back();
            element.pop_back();
        }
    }
};
