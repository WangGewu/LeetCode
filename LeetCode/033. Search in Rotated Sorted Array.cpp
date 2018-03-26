class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();//[l,r)
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] <= nums[r - 1])//如果mid处的值小于等于区间最右侧的值，说明mid到r-1是有序的
            {
                if (nums[mid] <= target && target <= nums[r - 1])//如果在target在mid-r-1处
                    l = mid + 1;
                else
                    r = mid;
            }
            else
            {
                if (nums[l] <= target&&target <= nums[mid])//如果在target在l-mid处
                    r = mid;
                else
                    l = mid + 1;
            }
        }
        return -1;
    }
};
