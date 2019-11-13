class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>result(2);
        //左边界
        int left=0,right=nums.size()-1;
        int pos=bf(nums,target,left,right);
        int last_pos=pos;
        while(pos!=-1)
        {
            last_pos=pos;
            pos=bf(nums,target,left,pos-1);
        }
        result[0]=last_pos;
        //右边界
        left=0;right=nums.size()-1;
        pos=bf(nums,target,left,right);
        last_pos=pos;
        while(pos!=-1)
        {
            last_pos=pos;
            pos=bf(nums,target,pos+1,right);
        }
        result[1]=last_pos;
        return result;
    }
    int bf(vector<int>& nums, int target,int left,int right)
    {
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                left=mid+1;
            else if(nums[mid]>target)
                right=mid-1;
        }
        return -1;
    }
};