/*
*4nums to 3nums to 2nums
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>result;
        if (nums.size()<4)
            return result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])continue;
            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                if (j>i + 1 && nums[j] == nums[j - 1])continue;
                int p = j + 1, q = nums.size() - 1;
                int x = target - nums[i] - nums[j];
                while (p < q)
                {
                    if (x == nums[p] + nums[q])
                    {
                        result.push_back({ nums[i],nums[j],nums[p],nums[q] });
                        while (p < q&&nums[p + 1] == nums[p])++p;
                        while (p < q&&nums[q - 1] == nums[q])--q;
                        ++p; --q;
                    }
                    else if (x > nums[p] + nums[q])
                        ++p;
                    else
                        --q;
                }
            }
        }
        return result;
    }
};