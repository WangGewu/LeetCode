//���Σ����һ�����ӳ�ʱ
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int left=0,right=heights.size()-1;
        return solve(heights,left,right);
    }
    int solve(vector<int>&heights,int left,int right)
    {
        if(left==right)
            return heights[left];
        if(left>right)
            return 0;
        int min_height=heights[left],min_posi=left;
        for(int i=left;i<=right;i++)//����С
            if(heights[i]<min_height)
            {
                min_height=heights[i];
                min_posi=i;
            }
        return max(max(solve(heights,left,min_posi-1),solve(heights,min_posi+1,right)),min_height*(right-left+1));//����СΪ�ֽ磬�Ƚ�left-right��left-��posi-1������posi+1��-right
    }
};