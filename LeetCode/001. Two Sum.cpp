class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result;
        map<int, int>res;
        for (int i = 0; i<nums.size(); i++)
        {
            int temp = target - nums[i];
            auto index = res.find(temp);
            if (index != res.end())
            {
                result.push_back(res[temp]);
                result.push_back(i);
                return result;
            }
            res[nums[i]] = i;
        }
        return result;
    }
};
