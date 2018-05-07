class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>element;
        sort(nums.begin(), nums.end());//先对nums排序，避免出现集合的元素一样，但位置不同的情况
        int min;
        for (int i = 0; i <= nums.size(); i++)//依次处理集合含有0—nums.size()个元素
        {
            min = INT_MIN;
            solve(result, element, nums, min, i);
        }
        return result;
    }
    void solve(vector<vector<int>>&result, vector<int>&element, vector<int>nums, int &min, int n)
    {
        if (element.size() == n)
        {
            result.push_back(element);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= min)continue;//min记录当前集合的最小值,下次递归从比min大的元素开始添加
            element.push_back(nums[i]);
            min = nums[i];
            solve(result, element, nums, min, n);
            min = element[element.size() - 1];
            element.pop_back();
        }
    }
};