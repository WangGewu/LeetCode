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

//2
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1,current=m+n-1;
        while(i>=0&&j>=0)
            nums1[current--]=nums1[i]>nums2[j]?nums1[i--]:nums2[j--];
        while(j>=0)//如果nums2没填完。还有一种情况是nums2填完了nums1没填完，这种情况下，nums1就已经有序了，直接返回
            nums1[current--]=nums2[j--];
    }   
};
