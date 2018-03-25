/*
 *�Ӻ���ǰ�ҳ���һ�������Ե�λ��pos
 *��pos���ҳ�����pos-1��С��ֵ��λ��
 *������Ȼ������pos���Ԫ��
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pos = nums.size() - 1;
        while (pos>0 && nums[pos] <= nums[pos - 1])//�Ӻ���ǰ�ҳ���һ�������Ե�λ��pos
            pos--;
        if (pos == 0)
        {
            sort(nums.begin(), nums.end());
            return;
        }
        int node = pos;
        int min = 99999999;
        for (int i = pos; i < nums.size(); i++)//��pos���ҳ�����pos - 1��С��ֵ��λ��
        {
            if (nums[i] > nums[pos - 1] && nums[i] < min)
            {
                node = i;
                min = nums[i];
            }
        }
        swap(nums[pos - 1], nums[node]); //������Ȼ������pos���Ԫ��
        sort(nums.begin() + pos, nums.end());
        return;
    }
};