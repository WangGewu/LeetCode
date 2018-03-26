class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] <= nums[r - 1])
            {
                if (nums[mid] <= target && target <= nums[r - 1])
                    l = mid + 1;
                else
                    r = mid;
            }
            else
            {
                if (nums[l] <= target&&target <= nums[mid])
                    r = mid;
                else
                    l = mid + 1;
            }
        }
        return -1;
    }
};