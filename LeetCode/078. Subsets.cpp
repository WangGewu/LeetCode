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
