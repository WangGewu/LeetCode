class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= 1 && nums[i]<nums.size() && nums[nums[i] - 1] != nums[i])//ʹ����ÿ��λ�ô�Ŷ�Ӧ�±�+1��ֵ
            {
                swap(nums[i], nums[nums[i] - 1]);
                i--;
            }
        }
        for (int i = 0; i < nums.size(); i++)//�Ҳ�������������
            if (nums[i] != i + 1)
                return i + 1;
        return nums.size() + 1;
    }
};