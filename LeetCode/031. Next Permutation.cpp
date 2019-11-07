/*
 *从后向前找出第一个递增对的位置pos
 *在pos后找出大于pos-1最小的值的位置
 *交换，然后重排pos后的元素
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pos = nums.size() - 1;
        while (pos>0 && nums[pos] <= nums[pos - 1])//从后向前找出第一个递增对的位置pos
            pos--;
        if (pos == 0)
        {
            sort(nums.begin(), nums.end());
            return;
        }
        int node = pos;
        int min = 99999999;
        for (int i = pos; i < nums.size(); i++)//在pos后找出大于pos - 1最小的值的位置
        {
            if (nums[i] > nums[pos - 1] && nums[i] < min)
            {
                node = i;
                min = nums[i];
            }
        }
        swap(nums[pos - 1], nums[node]); //交换，然后重排pos后的元素
        sort(nums.begin() + pos, nums.end());
        return;
    }
};

//二刷
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size=nums.size(),i=size-1;
        while(i>0&&nums[i]<=nums[i-1])
            i--;
        if(i==0)
            sort(nums.begin(),nums.end());
        else
        {
            int j=size-1;
            for(;j>=i;j--)
                if(nums[j]>nums[i-1])
                    break;
            swap(nums[j],nums[i-1]);
            sort(nums.begin()+i,nums.end());
        }
        return;
    }
};
