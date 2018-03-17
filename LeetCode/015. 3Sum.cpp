//转化为处理两数之和问题
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>value;
        if (nums.size() < 3)
            return value;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++)
        {
            if (i>0 && nums[i] == nums[i - 1])continue;
            int targe = 0 - nums[i];
            int p = i + 1, q = nums.size() - 1;
            while (p < q)
            {
                if (nums[p] + nums[q] == targe)
                {
                    value.push_back({ nums[i],nums[p],nums[q] });
                    while (p < q&&nums[p] == nums[p + 1])++p;
                    while (p < q&&nums[q] == nums[q - 1])--q;
                    p++; q--;
                }
                else if (nums[p] + nums[q] > targe)
                    q--;
                else
                    p++;
            }
        }
        return value;
    }
};