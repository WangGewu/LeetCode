class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>element;
        sort(nums.begin(), nums.end());//�ȶ�nums���򣬱�����ּ��ϵ�Ԫ��һ������λ�ò�ͬ�����
        for (int i = 0; i <= nums.size(); i++)//���δ����Ϻ���0��nums.size()��Ԫ��
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
            if (i <= posi)continue;//min��¼��ǰ���ϵ���Сֵ,�´εݹ�ӱ�min���Ԫ�ؿ�ʼ���
            element.push_back(nums[i]);
            solve(result, element, nums, n, i);
            element.pop_back();
        }
    }
};