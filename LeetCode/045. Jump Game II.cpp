class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        int currentMax = 0;
        int lastMax = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > lastMax)
            {
                cnt++;
                lastMax = currentMax;
            }
            currentMax = max(currentMax, nums[i] + i);
        }
        return cnt;
    }
};