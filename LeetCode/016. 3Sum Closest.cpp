class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        for (int k = 0;; k++)
            for (int i = 0; i < nums.size() - 2; i++)
            {
                for (int j = i + 1; j < nums.size() - 1; j++)
                {
                    if (find(nums.begin() + j + 1, nums.end(), target + k - (nums[i] + nums[j])) != nums.end())
                        return target + k;
                    if (find(nums.begin() + j + 1, nums.end(), target - k - (nums[i] + nums[j])) != nums.end())
                        return target - k;
                }
            }
    }
};