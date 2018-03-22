class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int i = 1;
        int cnt = 0;
        int temp = i;
        while (i < size)
        {
            if (nums[i] == nums[i - 1])
            {
                cnt++;
                if (cnt == 1)
                    temp = i;
                i++;
            }
            else
            {
                if (cnt > 0)
                {
                    i = temp + 1;
                    int hi = temp + cnt;
                    while (hi < size)
                        nums[temp++] = nums[hi++];
                    size = size - cnt;
                    cnt = 0;
                }
                else
                    i++;
            }
        }
        return size - cnt;
    }
};