//dp，官方题解的解法二
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        vector<vector<int>>width(matrix.size(),vector<int>(matrix[0].size(),0));
        int max_area=0,min_width;
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size();j++)
                {
                    if(j==0)
                        width[i][j]=(matrix[i][j]=='1'?1:0);
                    else
                        width[i][j]=(matrix[i][j]=='1'?width[i][j-1]+1:0);
                    min_width=width[i][j];
                    for(int k=i;k>=0&&width[k][j]!=0;k--)
                    {
                        min_width=min(min_width,width[k][j]);
                        max_area=max(max_area,min_width*(i-k+1));
                    }
                }
        return max_area;
    }
};