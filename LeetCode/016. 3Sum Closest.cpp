class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {\
        int result=0;
        bool flag=false;
        while(1)
        {
            flag=threeSum(nums,target-result);
            if(flag)
                return target-result;
            flag=threeSum(nums,target+result);
            if(flag)
                return target+result;
            result++;
        }
    }
    bool threeSum(vector<int>& nums,int target) {
        int result;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {   
            int sum=target-nums[i];
            int p=i+1,q=nums.size()-1;
            while(p<q)
            {
                if(nums[p]+nums[q]==sum)
                {
                    return true;
                }
                else if(nums[p]+nums[q]>sum)
                    q--;
                else
                    p++;
            }
        }
        return false;
    }
};
