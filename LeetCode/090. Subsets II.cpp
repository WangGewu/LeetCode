class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>element;
        sort(nums.begin(), nums.end());//先对nums排序，避免出现集合的元素一样，但位置不同的情况
        for (int i = 0; i <= nums.size(); i++)//依次处理集合含有0—nums.size()个元素
        {
            int posi = -1;
            solve(result, element, nums, i, posi);
        }
        return result;
    }
    void solve(vector<vector<int>>&result, vector<int>&element, vector<int>nums, int n, int posi)
    {
        if (element.size() == n)
        {
            if (find(result.begin(), result.end(), element) == result.end())
                result.push_back(element);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (i <= posi)continue;//min记录当前集合的最小值,下次递归从比min大的元素开始添加
            element.push_back(nums[i]);
            solve(result, element, nums, n, i);
            element.pop_back();
        }
    }
};