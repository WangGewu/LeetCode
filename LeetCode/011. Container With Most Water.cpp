class Solution {
public:
    int maxArea(vector<int>& height) {
        int max=0;
        int front=0,rear=height.size()-1;
        int v;
        while(rear>front)
        {
            v=min(height[front],height[rear])*(rear-front);
            if(v>max)
                max=v;
            if(height[front]<=height[rear])
                front++;
            else
                rear--;
        }
        return max;
    }
};
