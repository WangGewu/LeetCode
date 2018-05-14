class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pt = m + n - 1;
        while (m>0 || n>0)
        {
            if (m > 0 && n > 0)
            {
                if (nums1[m - 1] >= nums2[n - 1])
                {
                    nums1[pt--] = nums1[m - 1];
                    m--;
                }
                else
                {
                    nums1[pt--] = nums2[n - 1];
                    n--;
                }
            }
            else if (m > 0)
            {
                nums1[pt--] = nums1[m - 1];
                m--;
            }
            else if (n > 0)
            {
                nums1[pt--] = nums2[n - 1];
                n--;
            }
        }
    }
};