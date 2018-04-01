class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector <int> element;
        solve(res, nums, element);
        return res;
    }
    void solve(vector<vector<int>>&res, vector<int>& nums, vector<int>&element)
    {
        if (element.size() == nums.size())
        {
            res.push_back(element);
            return;
        }
        for (int i = 0; i < nums.size(); i++)//ÀàËÆÓÚCombination Sum
        {
            if (find(element.begin(), element.end(), nums[i]) != element.end())
                continue;
            element.push_back(nums[i]);
            solve(res, nums, element);
            element.pop_back();
        }
    }
};