class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int res = 0;
        while (l<r)
        {
            int minHeight = min(height[l], height[r]);
            if (height[l] == minHeight)
            {
                while (++l<r&&height[l]<minHeight)
                    res += minHeight - height[l];

            }
            else
            {
                while (--r>l&&height[r]<minHeight)
                {
                    res += minHeight - height[r];
                }
            }
        }
        return res;
    }
};