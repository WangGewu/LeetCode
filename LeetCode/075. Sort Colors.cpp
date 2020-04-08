class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int i = 0;
        while (l <= r&&i <= r)
        {
            if (nums[i] == 0 && i>l)swap(nums[i], nums[l++]);
            else if (nums[i] == 2 && i<r)swap(nums[i], nums[r--]);
            else i++;
        }
    }
};

//2
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int end=nums.size();
        for(int i=0;i<end;i++)
        {
            if(nums[i]==0)
            {
                nums.erase(i+nums.begin());
                nums.insert(nums.begin(),0);
            }
            else if(nums[i]==2)
            {
                nums.erase(i+nums.begin());
                nums.insert(nums.end(),2);
                i--;
                end--;
            }
        }
    }
};
