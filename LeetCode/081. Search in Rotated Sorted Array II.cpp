class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] == target)
                return true;
            if (nums[mid] == nums[l] && nums[mid] == nums[r]) { l++; r--; }
            else if (nums[mid] <= nums[r])
            {
                if (nums[mid] < target && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            else
            {
                if (nums[l] <= target&&target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return false;
    }
};


//2
//l-mid和mid-r至少一个有序,因此安装左、右有序分情况讨论
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0,r=nums.size();
        while(l<r)
        {
            int mid=(l+r)/2;
            if(nums[mid]==target)
                return true;
            if(nums[mid]==nums[l]&&nums[mid]==nums[r-1])//去除重复元素，使得mid至少与l和r中的一个不等，这样就可以判别左边还是右边有序。
            {
                l++;r--;
            }
            else if(nums[mid]<=nums[r-1])//右边有序
            {
                if(target>nums[mid]&&target<=nums[r-1])
                    l=mid+1;
                else
                    r=mid;
            }
            else//左边有序
            {
                if(target>=nums[l]&&target<nums[mid])
                    r=mid;
                else
                    l=mid+1;
            }
        }
        return false;
    }
};
