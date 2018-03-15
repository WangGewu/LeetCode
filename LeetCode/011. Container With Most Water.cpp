class Solution {
public:
    int maxArea(vector<int>& height) {
        int max=0;
        int l=0,r=height.size()-1;
        while(l!=r)
        {
            int h=min(height[l],height[r]);
            if((r-l)*h>max)
                max=(r-l)*min(height[l],height[r]);
            if(h==height[l])
                l++;
            else
                r--;
        }
        return max;
    }
};
