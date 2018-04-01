class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>element;
        vector<int>position;
        sort(nums.begin(), nums.end());
        solve(res, nums, element, position);
        return res;
    }
    void solve(vector<vector<int>>&res, vector<int>& nums, vector<int>&element, vector<int>& posi)
    {
        if (element.size() == nums.size())
        {
            res.push_back(element);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (find(posi.begin(), posi.end(), i) != posi.end())continue;
            if (i != 0 && nums[i] == nums[i - 1] && find(posi.begin(), posi.end(), i - 1) != posi.end())continue;
            element.push_back(nums[i]);
            posi.push_back(i);
            solve(res, nums, element, posi);
            element.pop_back();
            posi.pop_back();
        }
    }
};