class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= 1 && nums[i]<nums.size() && nums[nums[i] - 1] != nums[i])//使数组每个位置存放对应下标+1的值
            {
                swap(nums[i], nums[nums[i] - 1]);
                i--;
            }
        }
        for (int i = 0; i < nums.size(); i++)//找不不满足条件的
            if (nums[i] != i + 1)
                return i + 1;
        return nums.size() + 1;
    }
};