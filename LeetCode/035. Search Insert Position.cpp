class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l<r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid]<target)
                l = mid + 1;
            else if (target<nums[mid])
                r = mid;
            else
                return mid;
        }
        if (l<nums.size() && nums[l]<target)
            return l + 1;
        else
            return l;
    }
};