class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lastLen = nums.size();
        int cnt = 0;
        int currentLen = 1;
        for (int i = 0; i < nums.size() - cnt; i++)
        {
            if (i != 0 && nums[i] == nums[i - 1])currentLen++;
            else
            {
                if (currentLen > 2)//���ֵĸ�������2������remove
                {
                    cout << i << endl;
                    for (int j = i - currentLen + 2; j < nums.size() - cnt - (currentLen - 2); j++)
                        nums[j] = nums[j + currentLen - 2];
                    cnt += (currentLen - 2);
                    i = i - (currentLen - 2);//�ƶ���Ԫ��λ�÷����仯������i��ʹiָ��Ҫ�������һ��Ԫ��
                }
                currentLen = 1;
            }
        }
        if (currentLen>2)
            cnt += currentLen - 2;
        return lastLen - cnt;
    }
};