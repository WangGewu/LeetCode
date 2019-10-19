class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int p=1;
        int length=nums.size();
        if(length==0)
            return 0;
        for(int i=1;i<length;i++)
        {
            if(nums[i]!=nums[i-1])
            {
                nums[p]=nums[i];
                p++;
            }
        }
        return p;
    }
};
