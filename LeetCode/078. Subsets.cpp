class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>element;
        sort(nums.begin(), nums.end());//�ȶ�nums���򣬱�����ּ��ϵ�Ԫ��һ������λ�ò�ͬ�����
        int min;
        for (int i = 0; i <= nums.size(); i++)//���δ����Ϻ���0��nums.size()��Ԫ��
        {
            min = INT_MIN;
            solve(result, element, nums, min, i);
        }
        return result;
    }
    void solve(vector<vector<int>>&result, vector<int>&element, vector<int>nums, int &min, int n)
    {
        if (element.size() == n)
        {
            result.push_back(element);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= min)continue;//min��¼��ǰ���ϵ���Сֵ,�´εݹ�ӱ�min���Ԫ�ؿ�ʼ���
            element.push_back(nums[i]);
            min = nums[i];
            solve(result, element, nums, min, n);
            min = element[element.size() - 1];
            element.pop_back();
        }
    }
};