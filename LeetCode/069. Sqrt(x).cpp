class Solution {
public:
    int mySqrt(int x) {
        int result = 0;
        if (!x)return result;
        int l = 1, r = x;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (mid > x / mid)
                r = mid - 1;
            else if (mid <= x / mid)//l左边的数的平方都小于等于x
                l = mid + 1;
        }
        return l - 1;
    }
};