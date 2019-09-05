class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<float>sorted;
        int i = 0, j = 0;
        while (i<nums1.size() && j<nums2.size())
        {
            if (nums1[i] <= nums2[j])
            {
                sorted.push_back(nums1[i]);
                i++;
            }
            else
            {
                sorted.push_back(nums2[j]);
                j++;
            }
        }
        for (int k = i; k<nums1.size(); k++)
        {
            sorted.push_back(nums1[k]);
        }
        for (int k = j; k<nums2.size(); k++)
        {
            sorted.push_back(nums2[k]);
        }
        int nums = sorted.size();
        if (nums % 2 == 0)
            return (sorted[nums / 2] + sorted[nums / 2 - 1]) / 2;
        else
            return sorted[nums / 2];
    }
};