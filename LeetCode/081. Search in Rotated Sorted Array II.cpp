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